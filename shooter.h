#ifndef SHOOTER_H
#define SHOOTER_H

#include <Timer.h>
#include "feeder.h"
#include "ports.h"
#include "launcher.h"
#include "updateRegistry.h"
#include "612.h"

class Shooter {
private:
    Launcher launch;
    Feeder feed;
    bool shooting;
    Timer feedTimer;
    static void shotBtnHelper(void*);
    static void update_helper(void*);
    static const double FEEDER_TIMEOUT=2.0;
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
    void shoot(double);
    void abort();
    bool isShooting();
};

#endif
