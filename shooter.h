#ifndef SHOOTER_H
#define SHOOTER_H

#include "feeder.h"
#include "ports.h"
#include "launcher.h"
#include "updateregistry.h"
#include "612.h"

class Shooter {
private:
    Feeder feed;
    Launcher launch;
    unsigned int startCount;
    unsigned int curCount;
    bool shooting;
    static void shotBtnHelper(void*);
    static void update_helper(void*);
public:
    Shooter(hw_info, hw_info);
    float getCurrentSpeed();
    bool atSpeed();
    unsigned int getFrisbeeCount();
    void resetFrisbeeCount();
    void setSpeed(float);
    float getTargetSpeed();
    void getFeederDirection();
    void shoot();
    void setFeederForward();
    void setFeederBackward();
    void setFeederStop();
    ~Shooter();
};

#endif
