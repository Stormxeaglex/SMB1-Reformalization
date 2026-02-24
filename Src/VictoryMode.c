#include "VictoryMode.h"

extern uint8_t rCarry;
extern void ScrollScreen(register uint8_t) {}
extern void UpdScrollVar(void) {}

enum VictoryModeSubroutinesOptions {
    BridgeCollapse,
    SetupVictoryMode,
    PlayerVictoryWalk,
    PrintVictoryMessages,
    PlayerEndWorld          
}

void VictoryModeSubroutines(void) {
    switch (OperMode_Task) {
        case BridgeCollapse:        goto do_BridgeCollapse;
        case SetupVictoryMode:      goto do_SetupVictoryMode;
        case PlayerVictoryWalk:     goto do_PlayerVictoryWalk;
        case PrintVictoryMessages:  goto do_PrintVictoryMessages;
        case PlayerEndWorld:        goto do_PlayerEndWorld;
    }
    
    do_SetupVictoryMode:
        DestinationPageLoc = ScreenRight_PageLoc++;
        EventMusicQueue = MUSIC_END_OF_CASTLE
        OperMode_Task++
        return;
        
    do_PlayerVictoryWalk:
        //--Check when we should stop player autowalk--
        gVictoryWalkControl = 
            ((Player_PageLoc != DestinationPageLoc) || (Player_X_Position < 60));
        AutoControlPlayer(gVictoryWalkControl);
        
        //--Handle Auto Scrolling--
        if (ScreenLeft_PageLoc != DestinationPageLoc) {
            {
                gScrollFractional += 0x80; bool rCarry = (gScrollFraction < 0x80);
                ScrollScreen(1 + rCarry);
            }
            UpdScrollVar();
            gVictoryWalkControl += 1; //Asm weirdness to keep this true
        }
        
        //--Check if we should enter the next victory mode state after autowalk completes--
        if (gVictoryWalkControl == 0) {
            OperMode_Task++;
        }
        return;

    do_PrintVictoryMessages:
        // --Handle Logic For Waiting For The Next Valid State--
        if (gTimerUntilNextMsgState > 0 || gSavedMsgState >= UNUSED_STATE9) goto WaitUntilNextState;
        // PrimaryMsgCounter != 0 case (else part of the original beq)
        if (gSavedMsgState > INITIALIZE) {
            if (WorldNumber == World8) {
                if (gSavedMsgState < PRINCESS_MSG_1) 
                    goto WaitUntilNextState;
            } else {
                // MRetainerMsg (world 1‑7)
                if (gSavedMsgState < ANOTHER_CASTLE) 
                    goto WaitUntilNextState;
                //Note the SBC instruction is useless, and its removed from the C
                //the later iny and dey instructions also always cancel out
            }
            // fall through to ThankPlayer
        }
        //ThankPlayer
        // --Handle Execute Message State Logic--
        register MsgStates WorkingMsgState = gSavedMsgState
        if (WorkingMsgState == INITIALIZE) {     // Thank you mario or Thank you luigi message
            WorkingMsgState = (gCurrentPlayer==LUIGI) ? THANK_LUIGI : THANK_MARIO // Luigi uses message 1 
        } else {                          // After thanking, select world 8 or princess in another castle messages
            if (WorldNumber == World8) {
                // EvalForMusic
                if (WorkingMsgState == W8_PLAY_PRINCESS_MUSIC) {
                    EventMusicQueue = VictoryMusic;
                }
            } else {
                if (WorkintMsgState == W1–7_END_DELAY) {
                    goto WaitUntilNextState;
                } else if  (WorkingMsgState >= W1–7_EXIT_MSG) {
                    goto SetEndTimerAndStopPrinting;
                }
            }  
        }
        // --Update the Pointer to the message buffer--
        // PrintMsg
        //($0c-$0d = first), ($0e = world 1-7's), ($0f-$12 = world 8's)
        VRAM_Buffer_AddrCtrl = WorkingMsgState + 0x0C;
        goto WaitUntilNextState;
        
        WaitUntilNextState: { // Wait for Secondary timer before displaying next message
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
        
    doPlayerEndWorld:
    
    
}