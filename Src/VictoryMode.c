  
void PrintVictoryMessages(void) {
    
    enum messageStates {
        INITIALISE = 0,
        
        THANK_MARIO = 0,
        THANK_LUIGI = 1,
        
        W1–7_ANOTHER_CASTLE = 2,
        W1–7_END_DELAY = 3,
        W1–7_EXIT_MSG = 4,
        
        W8_PLAY_PRINCESS_MUSIC = 3,
        W8_PRINCESS_MSG_1 = 3,
        W8_PRINCESS_MSG_2 = 4,
        W8_SECOND_QUEST_MSG_1 = 5,
        W8_SECOND_QUEST_MSG_2 = 6,
        W8_EXIT_MSG = 7,
        
        UNUSED_STATE9 = 9
    }
    
    //
    // --Handle Logic For Waiting For The Next Valid State--
    //
    
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
    
    register u8 WorkingMsgState = gSavedMsgState
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
        // delay timer before displaying next message
        uint8_t prevValForOverflowCheck = gTimerUntilNextMsgState;
        gTimerUntilNextMsgState += 4;
        if (gTimerUntilNextMsgState < prevValForOverflowCheck)
            gMsgState++;
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