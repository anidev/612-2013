#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <Jaguar.h>
#include <CANJaguar.h>
#include <PIDController.h>
#include <cstdio>
#include "two_controller.h"
#include "PIDCounter.h"
#include "ports.h"
#include "612.h"

class Launcher {
private:
    static const float AT_SPEED_TOLERANCE = 1.5; //percent
    static const float PID_P = 0.005f;
    static const float PID_I = 0.0f;
    static const float PID_D = 0.002f;
    unsigned int count;
    float targetSpeed;
    bool targetSet;
#ifdef Suzie
    two_controller<Jaguar> launcherWheel;
    PIDCounter launcherSensor; // return RPS
    PIDController pid;
#else
    CANJaguar launcherWheel;
#endif //Suzie
    void update();
    static void update_helper(void*);
public:
#ifdef Suzie
    Launcher(hw_info,hw_info,hw_info);
#else
    Launcher(canport_t);
#endif //Suzie
    ~Launcher();
    void stop();
    bool atSpeed();
    void setSpeed(float);
    float getCurrentSpeed();
    float getTargetSpeed();
    unsigned int getFrisbeeCount();
    void resetFrisbeeCount();
};

#endif // LAUNCHER_H
