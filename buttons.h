#ifdef buttons
#define buttons

//DRIVER CONTROLS
//Axi
const int Driver_Axis_LeftAnalogX_TankDriveLeft   = 1;
const int Driver_Axis_LeftAnalogY_TankDriveLeft   = 2;
const int Driver_Axis_RightAnalogX_TankDriveRight = 3;
const int Driver_Axis_RightAnalogY_TankDriveRight = 4;
const int Driver_Axis_DPadX_ArcadeDrive           = 6;
const int Driver_Axis_DPadY_ArcadeDrive           = 7;
//Buttons
const int Driver_Btn_X_LogSensors    = 1;
const int Driver_Btn_A_LiftPreset    = 2;
const int Driver_Btn_B_ToggleLED     = 3;
const int Driver_Btn_Y_ResetEncoders = 4;
const int Driver_Btn_L1_ShiftLow     = 5;
const int Driver_Btn_R1_ShiftHigh    = 6;
const int Driver_Btn_L2_SwivelLeft   = 7;
const int Driver_Btn_L2_SwivelRight  = 8;
const int Driver_Btn_Sel_NormalMode  = 9;
const int Driver_Btn_Start_ClimbMode = 10;
const int Driver_Btn_L3              = 11; //not used
const int Driver_Btn_L4              = 12; //not used

//GUNNER CONTROLS
//Axi
const int Gunner_Axis_LeftAnalogX         = 1; //not used
const int Gunner_Axis_leftAnalogY         = 2; //not used
const int Gunner_Axis_RightAnalogX        = 3;
const int Gunner_Axis_RightAnalogY        = 4;
const int Gunner_Axis_DPadX_Feeder        = 5; 
const int Gunner_Axis_DPadY_ShooterWhlSpd = 6;
//Buttons
const int Gunner_Btn_X_ShooterPresetOne     = 1;
const int Gunner_Btn_A_SingleShot           = 2;
const int Gunner_Btn_B_MultiShot            = 3;
const int Gunner_Btn_Y_ShooterPresetTwo     = 4;
const int Gunner_Btn_L1_LiftUp              = 5;
const int Gunner_Btn_R1_LiftDown            = 6;
const int Gunner_Btn_L2_SwivelLeft          = 7;
const int Gunner_Btn_R2_SwivelRight         = 8;
const int Gunner_Btn_Sel_ShooterPresetThree = 9;
const int Gunner_Btn_ToggleShooterWheel     = 10;
const int Gunner_Btn_L3                     = 11; //not used
const int Gunner_Btn_L4                     = 12; //not used





#endif
