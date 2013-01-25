#if 0
#ifndef SHOOTER_H
#define SHOOTER_H

#include "feeder.h"
#include "lift.h"
#include "ports.h"
#include "launcher.h"

class Shooter {
private:
    enum subState {
        userControlled, visionAnalysis, aiming, shooting
    } currentState;
    Launcher launcherWheel;
    Lift angleAdjuster;
    Feeder feed;
    void update();
    void doAiming();
    void doShooting();
    void doVisionAnalysis();
    void doUserControlled();
public:
    Shooter(hw_info,hw_info,hw_info);
    ~Shooter();
    void autoShoot();
    void setToUserControlled();
    void resetShotCount();
    unsigned int getShotCount();
};

#endif
#endif
