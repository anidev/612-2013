#ifndef ENHANCED_SHOOTER_H
#define ENHANCED_SHOOTER_H

#include <CANJaguar.h>
#include <Jaguar.h>
#include <Counter.h>
#include <PIDController.h>
#include "main.h"
class robot_class;

class EnhancedShooter {
private:
    enum direction_t { //Feeder
        FORWARD = -1,
        BACKWARD = 1,
        STOP = 0
    };
    static const float FEEDER_SPEED = 0.25f;
    CANJaguar wheel;
    CANJaguar lift;
    Jaguar feeder;
    Counter HalEffect;
    EnhancedJoystick* driver;
    EnhancedJoystick* gunner;
public:
    static const unsigned int GUNNER_BTN_SHOOTER_WHEEL    = 1;
    static const unsigned int GUNNER_BTN_LIFT_UP          = 5;
    static const unsigned int GUNNER_BTN_LIFT_DOWN        = 6;
    static const unsigned int GUNNER_BTN_LIFT_LOAD_PRESET = 10;
    static const unsigned int GUNNER_AXIS_FEEDER          = 5;
    static const float LIFT_POWER = 0.4f;
    EnhancedShooter(int,int,robot_class::hw_info,robot_class::hw_info,void*);
    void setWheelPower(float);
    void setFeeder(direction_t);
    void setLiftPower(float);
    void update(); //Hal Affect Stop
    void doControls();
    void stopAll();
    void stopWheel();
    void stopLift();
    void stopFeeder();
    //Todo add the 4 below
    void setAngle();
    void setSpeed();
    void atAngle(float);
    void atSpeed();
    static void update_helper(void*);
    static void disable(void*);
};

#endif
