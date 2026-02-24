enum VictoryModeOperationStates {
    BridgeCollapse,
    SetupVictoryMode,
    PlayerVictoryWalk,
    PrintVictoryMessages,
    PlayerEndWorld          
};

typedef enum {
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
} MsgStates;