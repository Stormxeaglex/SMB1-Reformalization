#include "VictoryMode.h"
#define P1_PRESSING(button) ((SavedJoypadP1Bits & button) == button)
#define P2_PRESSING(button) ((SavedJoypadP2Bits & button) == button)
extern uint8_t rCarry;
extern void ScrollScreen(register uint8_t) {}
extern void UpdScrollVar(void) {}





void VictoryModeSubroutines(void) {
    //-O don't verify if the value is in range
    switch (OperMode_Task) {
        case do_BridgeCollapse:        return BridgeCollapse();         //-O TAIL CALL
        case do_SetupVictoryMode:      return SetupVictoryMode();       //-O TAIL CALL
        case do_PlayerVictoryWalk:     return PlayerVictoryWalk();      //-O TAIL CALL
        case do_PrintVictoryMessages:  return PrintVictoryMessages();   //-O TAIL CALL
        case do_PlayerEndWorld:        return PlayerEndWorld();         //-O TAIL CALL
    }
}

extern void BridgeCollapse ( void ) { //Probably move to bowser.c
    if (Enemy_ID->BowserFront_Offset == BOWSER) { //Fix the pointer indexing, this wont compile
        ObjectOffset = BowserFront_Offset;
        if (Enemy_State->BowserFront_Offset != 0) {//Fix the pointer indexing, this wont compile
            return RemoveBridge();                 //Add Enum BOWSER_NORMAL_STATE
        }
        
    }
}
BridgeCollapse:
       ldx BowserFront_Offset    ;get enemy offset for bowser
       lda Enemy_ID,x            ;check enemy object identifier for bowser
       cmp #Bowser               ;if not found, branch ahead,
       bne SetM2                 ;metatile removal not necessary
       stx ObjectOffset          ;store as enemy offset here
       lda Enemy_State,x         ;if bowser in normal state, skip all of this
       beq RemoveBridge
       and #%01000000            ;if bowser's state has d6 clear, skip to silence music
       beq SetM2
       lda Enemy_Y_Position,x    ;check bowser's vertical coordinate
       cmp #$e0                  ;if bowser not yet low enough, skip this part ahead
       bcc MoveD_Bowser
SetM2: lda #Silence              ;silence music
       sta EventMusicQueue
       inc OperMode_Task         ;move onto next secondary mode in autoctrl mode
       jmp KillAllEnemies        ;jump to empty all enemy slots and then leave 
    
    
void SetupVictoryMode (void) {
    DestinationPageLoc = ScreenRight_PageLoc++;
    EventMusicQueue = MUSIC_END_OF_CASTLE
    OperMode_Task++
    return;
}

void PlayerVictoryWalk (void) {
    //  --Check when we should stop player autowalk--
    gVictoryWalkControl = ( (Player_PageLoc != DestinationPageLoc)
                            || (Player_X_Position < 60) );
                            
    AutoControlPlayer(gVictoryWalkControl);
    
    //              --Handle Auto Scrolling--
    if (ScreenLeft_PageLoc != DestinationPageLoc) {
        {
            gScrollFractional += 0x80; bool rCarry = (gScrollFraction < 0x80);
            ScrollScreen(1 + rCarry);
        }
        UpdScrollVar();
        gVictoryWalkControl += 1; //Asm weirdness to keep this true
    }
    
    // --Check if we should enter the next victory mode state-- 
    //              --after autowalk completes--
    if (gVictoryWalkControl == 0) {
        OperMode_Task++;
    }
    return;
}

void PrintVictoryMessages (void) {
    // --Handle Logic For Waiting For The Next Valid State--
    if (gTimerUntilNextMsgState > 0 || gSavedMsgState >= UNUSED_STATE9) goto WaitUntilNextState;
    if (gMsgState > INITIALIZE) {
        if (WorldNumber == World8) {
            if (gMsgState < PRINCESS_MSG_1) 
                goto WaitUntilNextState;
        } else {
            if (gMsgState < ANOTHER_CASTLE) 
                goto WaitUntilNextState;
        }
    }
    
    //  --Handle Execute Message State Logic and associated events--
    register MsgStates WorkingMsgState = MsgState
    if (WorkingMsgState == INITIALIZE) {
        WorkingMsgState = (gCurrentPlayer==LUIGI) ? THANK_LUIGI : THANK_MARIO // Luigi uses message 1 
    } else {                          // After thanking, select world 8 or princess in another castle messages
        if (WorldNumber == World8) {
            if (WorkingMsgState == W8_PLAY_PRINCESS_MUSIC) 
                EventMusicQueue = VictoryMusic;
        } else {
            if (WorkingMsgState == W1–7_END_DELAY) 
                goto WaitUntilNextState;
            else if (WorkingMsgState >= W1–7_EXIT_MSG) 
                goto SetEndTimerAndStopPrinting;
        }  
    }
    
    // --Update the Pointer to the message buffer--
    VRAM_Buffer_AddrCtrl = WorkingMsgState + 0x0C;
    goto WaitUntilNextState;
    
    // --Delay Next State by using gTimerUntilNextMsgState--
    WaitUntilNextState: {
        {
            gTimerUntilNextMsgState += 4; bool rCarry = (gTimerUntilNextMsgState < 4);
            gMsgState += rCarry;
        }
        if (gMsgState >= W8_EXIT_MSG)
            goto SetEndTimerAndStopPrinting;
        return;
    }
    
    SetEndTimerAndStopPrinting: {
        WorldEndTimer = 6;
        OperMode_Task++;
        return;
        //Vars are cleared later by code that Ram up to $074b
    }
}

void PlayerEndWorld (void) {
    if (WorldEndTimer > 0) return;
    if (WorldNumber < WORLD_8) {
        //  --Setup vars to load the next world--
        AreaNumber = 0; LevelNumber = 0; OperMode_Task = 0;
        WorldNumber++;
        LoadAreaPointer();
        OperMode = GAME_MODE;
        return;
    } else {
        //  --Check if P1 or P2 is holding B to--
        //    --End the game or switch to P2--
        if (P1_PRESSING(B_BUTTON) || P2_PRESSING(B_BUTTON)) {
            WorldSelectEnableFlag = 1;
            NumberofLives = 0;
            TerminateGame();
        }
        return;
    }
}
