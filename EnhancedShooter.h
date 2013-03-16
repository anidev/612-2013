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
    enum direction_t {
        FORWARD = -1,
        BACKWARD = 1,
        STOP = 0
    };
    CANJaguar wheel;
    CANJaguar lift;
    Jaguar feeder;
    Counter HalEffect;
    EnhancedJoystick* driver;
    EnhancedJoystick* gunner;
public:
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
    static void update_helper(void*);
    static void disable(void*);
};

#endif
