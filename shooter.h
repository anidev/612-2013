#ifndef SHOOTER_H
#define SHOOTER_H

#include "feeder.h"
#include "ports.h"
#include "launcher.h"
#include "updateregistry.h"
#include "612.h"

class Shooter {
private:
    Launcher launch;
    Feeder feed;
    unsigned int startCount;
    unsigned int curCount;
    bool shooting;
    static void shotBtnHelper(void*);
    static void update_helper(void*);
public:
    Shooter(hw_info, hw_info, hw_info);
    ~Shooter();
    // Launcher
    void setSpeed(float);
    float getTargetSpeed();
    float getCurrentSpeed();
    bool atSpeed();
    unsigned int getFrisbeeCount();
    void resetFrisbeeCount();
    // Feeder
    void setFeederForward();
    void setFeederBackward();
    void setFeederStop();
    Feeder::direction_t getFeederDirection();
    // Global shooter stuff
    void update();
    void shoot();
    void abort();
};

#endif
