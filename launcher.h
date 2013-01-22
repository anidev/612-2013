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
    float getSpeed();
    Jaguar shooterWheel;
public:
    Launcher(hw_info);
    ~Launcher();
    void start();
    void stop();
    void update();
    bool atSpeed();
    unsigned int getFrisbeeCount();
    void resetFrisbeeCount();
    void setSpeed(float); //rpm
};

#endif // LAUNCHER_H
