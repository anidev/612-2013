#if 0
#ifndef SHOOTER_H
#define SHOOTER_H

#include "feeder.h"
#include "lift.h"
#include "ports.h"
#include "launcher.h"
#include "updateregistry.h"

class Shooter {
friend class GunnerUI;
private:
    enum subState {
        USER_CONTROLLED,
        VISION_ANALYSIS,
        AIMING,
        SHOOTING
    } currentState;
    void update();
    void doAiming();
    void doShooting();
    void doVisionAnalysis();
    void lineUpHorizontal();
    void setAngleOfAttack();
    bool HorizontalAlignment;
    bool angleSet;
    static void update_helper(void*);
public:
    Shooter(hw_info,hw_info,hw_info);
    ~Shooter();
    void autoShoot();
    void setToUserControlled();
    void resetShotCount();
    unsigned int getShotCount();
    void shoot();
protected:
    Launcher launcherWheel;
    Lift angleAdjuster;
    Feeder feed;
};

#endif
#endif
