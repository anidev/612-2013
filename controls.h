#ifndef CONTROLS_H
#define CONTROLS_H

//DRIVER CONTROLS
//Axes
const unsigned int Driver_Axis_TankLeft     =  2;
const unsigned int Driver_Axis_TankRight    =  4;
const unsigned int Driver_Axis_Arcade       =  6;
//Buttons
const unsigned int Driver_Btn_LogSensors    =  1;
const unsigned int Driver_Btn_ToggleLED     =  3;
const unsigned int Driver_Btn_ResetEncoders =  4;
const unsigned int Driver_Btn_ShiftLow      =  5;
const unsigned int Driver_Btn_ShiftHigh     =  6;
const unsigned int Driver_Btn_SwivelLeft    =  7;
const unsigned int Driver_Btn_SwivelRight   =  8;
const unsigned int Driver_Btn_NormalMode    =  9;
const unsigned int Driver_Btn_ClimbMode     = 10;

//GUNNER CONTROLS
//Axes
const unsigned int Gunner_Axis_Feeder        =  5;
const unsigned int Gunner_Axis_ShooterSpeed  =  6;
//Buttons
const unsigned int Gunner_Btn_PresetOne      =  1;
const unsigned int Gunner_Btn_SingleShot     =  2;
const unsigned int Gunner_Btn_MultiShot      =  3;
const unsigned int Gunner_Btn_PresetTwo      =  4;
const unsigned int Gunner_Btn_LiftUp         =  5;
const unsigned int Gunner_Btn_LiftDown       =  6;
const unsigned int Gunner_Btn_SwivelLeft     =  7;
const unsigned int Gunner_Btn_SwivelRight    =  8;
const unsigned int Gunner_Btn_ShooterRev     =  9;
const unsigned int Gunner_Btn_LiftLoadPreset = 10;

#endif // CONTROLS_H
