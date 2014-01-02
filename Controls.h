#ifndef CONTROLS_H
#define CONTROLS_H

//XBox Controller: L2 and R2 are axes, not buttons

typedef unsigned int Button;
typedef unsigned int Axis;
enum Trigger {
    TRIG_NONE = 0,
    TRIG_L = -1,
    TRIG_R = 1
};
static const Axis TRIGGER_AXIS                       = 3;

//Driver
static const Button DRIVER_SHIFT_LOW                 = 5;//L1 (LB)
static const Button DRIVER_SHIFT_HIGH                = 6;//R1 (RB)
static const Button DRIVER_BTN_NORMAL_STATE          = 7;//Select
static const Button DRIVER_BTN_CLIMBING_STATE        = 8;//Start

static const Trigger DRIVER_SWIVEL_LEFT              = TRIG_L;//L2 (LT)
static const Trigger DRIVER_SWIVEL_RIGHT             = TRIG_R;//R2 (RT)

static const Axis DRIVER_LEFT_DRIVE_AXIS             = 2;//L Stick
static const Axis DRIVER_RIGHT_DRIVE_AXIS            = 5;//R Stick

//Gunner
static const Button GUNNER_BTN_SHOOTER_WHEEL         = 3;//X
static const Button GUNNER_BTN_PRESET_BACK           = 4;//Y
static const Button GUNNER_BTN_PRESET_FRONT          = 1;//A
static const Button GUNNER_BTN_LIFT_LOAD_PRESET      = 2;//B
static const Button GUNNER_BTN_LIFT_UP               = 6;//R1 (RB)
static const Button GUNNER_BTN_LIFT_DOWN             = 5;//L1 (LB)
static const Button GUNNER_BTN_SUCCESS_LOG           = 7;//back
static const Button GUNNER_BTN_SHOOTER_WHEEL_REV     = 8;//start

static const Trigger GUNNER_SWIVEL_LEFT              = TRIG_L;//L2 (LT)
static const Trigger GUNNER_SWIVEL_RIGHT             = TRIG_R;//R2 (RT)

static const Axis GUNNER_AXIS_FEEDER                 = 6;//dpad horiz

#endif
