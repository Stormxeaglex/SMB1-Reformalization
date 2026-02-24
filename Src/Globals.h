; GAME SPECIFIC DEFINES

ObjectOffset          = $08

FrameCounter          = $09

SavedJoypadBits       = $06fc
SavedJoypad1Bits      = $06fc
SavedJoypad2Bits      = $06fd
JoypadBitMask         = $074a
JoypadOverride        = $0758

A_B_Buttons           = $0a
PreviousA_B_Buttons   = $0d
Up_Down_Buttons       = $0b
Left_Right_Buttons    = $0c

GameEngineSubroutine  = $0e

Mirror_PPU_CTRL_REG1  = $0778
Mirror_PPU_CTRL_REG2  = $0779

OperMode              = $0770
OperMode_Task         = $0772
ScreenRoutineTask     = $073c

GamePauseStatus       = $0776
GamePauseTimer        = $0777

DemoAction            = $0717
DemoActionTimer       = $0718

TimerControl          = $0747
IntervalTimerControl  = $077f

Timers                = $0780
SelectTimer           = $0780
PlayerAnimTimer       = $0781
JumpSwimTimer         = $0782
RunningTimer          = $0783
BlockBounceTimer      = $0784
SideCollisionTimer    = $0785
JumpspringTimer       = $0786
GameTimerCtrlTimer    = $0787
ClimbSideTimer        = $0789
EnemyFrameTimer       = $078a
FrenzyEnemyTimer      = $078f
BowserFireBreathTimer = $0790
StompTimer            = $0791
AirBubbleTimer        = $0792
ScrollIntervalTimer   = $0795
EnemyIntervalTimer    = $0796
BrickCoinTimer        = $079d
InjuryTimer           = $079e
StarInvincibleTimer   = $079f
ScreenTimer           = $07a0
WorldEndTimer         = $07a1
DemoTimer             = $07a2

Sprite_Data           = $0200

Sprite_Y_Position     = $0200
Sprite_Tilenumber     = $0201
Sprite_Attributes     = $0202
Sprite_X_Position     = $0203

ScreenEdge_PageLoc    = $071a
ScreenEdge_X_Pos      = $071c
ScreenLeft_PageLoc    = $071a
ScreenRight_PageLoc   = $071b
ScreenLeft_X_Pos      = $071c
ScreenRight_X_Pos     = $071d

PlayerFacingDir       = $33
DestinationPageLoc    = $34
VictoryWalkControl    = $35
ScrollFractional      = $0768
PrimaryMsgCounter     = $0719
SecondaryMsgCounter   = $0749

HorizontalScroll      = $073f
VerticalScroll        = $0740
ScrollLock            = $0723
ScrollThirtyTwo       = $073d
Player_X_Scroll       = $06ff
Player_Pos_ForScroll  = $0755
ScrollAmount          = $0775

AreaData              = $e7
AreaDataLow           = $e7
AreaDataHigh          = $e8
EnemyData             = $e9
EnemyDataLow          = $e9
EnemyDataHigh         = $ea

AreaParserTaskNum     = $071f
ColumnSets            = $071e
CurrentPageLoc        = $0725
CurrentColumnPos      = $0726
BackloadingFlag       = $0728
BehindAreaParserFlag  = $0729
AreaObjectPageLoc     = $072a
AreaObjectPageSel     = $072b
AreaDataOffset        = $072c
AreaObjOffsetBuffer   = $072d
AreaObjectLength      = $0730
StaircaseControl      = $0734
AreaObjectHeight      = $0735
MushroomLedgeHalfLen  = $0736
EnemyDataOffset       = $0739
EnemyObjectPageLoc    = $073a
EnemyObjectPageSel    = $073b
MetatileBuffer        = $06a1
BlockBufferColumnPos  = $06a0
CurrentNTAddr_Low     = $0721
CurrentNTAddr_High    = $0720
AttributeBuffer       = $03f9

LoopCommand           = $0745

DisplayDigits         = $07d7
TopScoreDisplay       = $07d7
ScoreAndCoinDisplay   = $07dd
PlayerScoreDisplay    = $07dd
GameTimerDisplay      = $07f8
DigitModifier         = $0134

VerticalFlipFlag      = $0109
FloateyNum_Control    = $0110
ShellChainCounter     = $0125
FloateyNum_Timer      = $012c
FloateyNum_X_Pos      = $0117
FloateyNum_Y_Pos      = $011e
FlagpoleFNum_Y_Pos    = $010d
FlagpoleFNum_YMFDummy = $010e
FlagpoleScore         = $010f
FlagpoleCollisionYPos = $070f
StompChainCounter     = $0484

VRAM_Buffer1_Offset   = $0300
VRAM_Buffer1          = $0301
VRAM_Buffer2_Offset   = $0340
VRAM_Buffer2          = $0341
VRAM_Buffer_AddrCtrl  = $0773
Sprite0HitDetectFlag  = $0722
DisableScreenFlag     = $0774
DisableIntermediate   = $0769
ColorRotateOffset     = $06d4

TerrainControl        = $0727
AreaStyle             = $0733
ForegroundScenery     = $0741
BackgroundScenery     = $0742
CloudTypeOverride     = $0743
BackgroundColorCtrl   = $0744
AreaType              = $074e
AreaAddrsLOffset      = $074f
AreaPointer           = $0750

PlayerEntranceCtrl    = $0710
GameTimerSetting      = $0715
AltEntranceControl    = $0752
EntrancePage          = $0751
NumberOfPlayers       = $077a
WarpZoneControl       = $06d6
ChangeAreaTimer       = $06de

MultiLoopCorrectCntr  = $06d9
MultiLoopPassCntr     = $06da

FetchNewGameTimerFlag = $0757
GameTimerExpiredFlag  = $0759

PrimaryHardMode       = $076a
SecondaryHardMode     = $06cc
WorldSelectNumber     = $076b
WorldSelectEnableFlag = $07fc
ContinueWorld         = $07fd

CurrentPlayer         = $0753
PlayerSize            = $0754
PlayerStatus          = $0756

OnscreenPlayerInfo    = $075a
NumberofLives         = $075a ;used by current player
HalfwayPage           = $075b
LevelNumber           = $075c ;the actual dash number
Hidden1UpFlag         = $075d
CoinTally             = $075e
WorldNumber           = $075f
AreaNumber            = $0760 ;internal number used to find areas

CoinTallyFor1Ups      = $0748

OffscreenPlayerInfo   = $0761
OffScr_NumberofLives  = $0761 ;used by offscreen player
OffScr_HalfwayPage    = $0762
OffScr_LevelNumber    = $0763
OffScr_Hidden1UpFlag  = $0764
OffScr_CoinTally      = $0765
OffScr_WorldNumber    = $0766
OffScr_AreaNumber     = $0767   