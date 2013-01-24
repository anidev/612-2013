#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <Jaguar.h>
#include <cstdio>
#include "ports.h"

class Launcher {
private:
    static const int COUNT_THRESHOLD = 70; //rpm
    static const int ON_SPEED = 100;//rpm
    static const float AT_SPEED_TOLERANCE = 2; //rpm
    unsigned int count;
    float targetSpeed;
    Jaguar shooterWheel;
public:
    Launcher(hw_info,hw_info,hw_info);
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
