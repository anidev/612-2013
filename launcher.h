#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <Jaguar.h>
#include <Counter.h>
#include <cstdio>
#include "ports.h"

class Launcher {
private:
    static const float AT_SPEED_TOLERANCE = 2; //rpm
    unsigned int count;
    float targetSpeed;
    bool targetSet;
    Jaguar launcherWheel;
    Counter launcherSensor; // return RPM
public:
    Launcher(hw_info,hw_info);
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
