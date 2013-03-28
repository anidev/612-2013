#ifndef ENHANCED_SHOOTER_H
#define ENHANCED_SHOOTER_H

#include <CANJaguar.h>
#include <Talon.h>
#include <Counter.h>
#include <PIDController.h>
#include "main.h"
#include "PIDCounter.h"
#include "Hardware.h"
#include "Controls.h"

class robot_class;

class EnhancedShooter {
private:
    //PID Values
    //Todo get Vlues
    static const float LIFT_P = 0.01f;
    static const float LIFT_I = 0.01f;
    static const float LIFT_D = 0.01f;

    static const float WHEEL_P = 0.3f;
    static const float WHEEL_I = 0.005f;
    static const float WHEEL_D = 0.0f;
    static const float WHEEL_TOLERANCE = 2.0f;
    
    static const float FEEDER_SPEED = 0.25f;
    

    static const float LIFT_TOLERANCE = 0.1f;
    static const float MIN_POT_VAL = 0.00f; //Lift
    static const float MAX_POT_VAL = 1.00f; //Lift
    static const float LIFT_LOAD_PRESET = 0;
    
    CANJaguar wheel;
    CANJaguar lift;
    Talon feeder;
    Counter HalEffect; // for wheel
    EnhancedJoystick* driver;
    EnhancedJoystick* gunner;
    robot_class::state* robotState;
    PIDCounter wheelCount;
    PIDController wheelCommandCenter;
    float liftAngleToPot(float);
public:
    enum direction { //Feeder
            FORWARD = -1,
            BACKWARD = 1,
            STOP = 0
    };
    static const float LIFT_POWER = 0.4f;
    EnhancedShooter(int,hw_info,int,hw_info,hw_info,void*);
    void setWheelPower(float);
    void setFeeder(direction);
    void setLiftPower(float);
    void update(); //Hal Affect Stop
    void doControls();
    void stopAll();
    void stopWheel();
    void stopLift();
    void stopFeeder();
    void setAngle(float);
    void setSpeed(float);
    bool atAngle(float);
    bool atSpeed(float);
    static void update_helper(void*);
    static void disable(void*);
    static void liftPreset(void*);
};

#endif
