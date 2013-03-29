#ifndef CONTROLS_H
#define CONTROLS_H

typedef unsigned int Button;
//Driver
static const Button DRIVER_SHIFT_LOW    = 5;
static const Button DRIVER_SHIFT_HIGH   = 6;
static const Button DRIVER_SWIVEL_LEFT  = 7;
static const Button DRIVER_SWIVEL_RIGHT = 8;
static const Button DRIVER_BTN_NORMAL_STATE   = 9;
static const Button DRIVER_BTN_CLIMBING_STATE = 10;

static const unsigned int DRIVER_LEFT_DRIVE_AXIS  = 2;
static const unsigned int DRIVER_RIGHT_DRIVE_AXIS = 4;

//Gunner
static const Button GUNNER_BTN_SHOOTER_WHEEL     = 1;
static const Button GUNNER_BTN_PRESET_BACK       = 4;
static const Button GUNNER_BTN_PRESET_FRONT      = 2;
static const Button GUNNER_BTN_LIFT_LOAD_PRESET  = 3;
static const Button GUNNER_BTN_LIFT_UP           = 5;
static const Button GUNNER_BTN_LIFT_DOWN         = 6;
static const Button GUNNER_SWIVEL_LEFT           = 7;
static const Button GUNNER_SWIVEL_RIGHT          = 8;
static const Button GUNNER_BTN_SUCCESS_LOG       = 9;
static const Button GUNNER_BTN_SHOOTER_WHEEL_REV = 10;

static const unsigned int GUNNER_AXIS_FEEDER     = 5;

#endif
