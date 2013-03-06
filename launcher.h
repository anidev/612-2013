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
#include "dataLogger.h"

class Launcher {
private:
    static const float AT_SPEED_TOLERANCE = 0.15; //percent
    static const float SHOT_DROP_TOLERANCE = 20; //RPS
    unsigned int count;
    float targetSpeed;
    bool targetSet;
    bool reachedSpeed;
#ifdef Suzie
    two_controller<Jaguar> launcherWheel;
#else
    CANJaguar launcherWheel;
#endif //Suzie
    void update();
    static void update_helper(void*);
public:
    static const float MAX = 70.0f;
#ifdef Suzie
    Launcher(hw_info,hw_info,hw_info);
#else
    Launcher(canport_t,hw_info);
#endif //Suzie
    ~Launcher();
    void stop();
    bool atSpeed();
    void setSpeed(float);
    float getCurrentSpeed();
    float getTargetSpeed();
    unsigned int getFrisbeeCount();
    void resetFrisbeeCount();
    bool dropDetected();
protected:
    //TODO Add dataLogger as Friend to compile
    PIDCounter launcherSensor; // return RPS
    PIDController pid;
};

#endif // LAUNCHER_H
