#if 0
#include "shooter.h"
#include "shooterAim.h"
#include "612.h"
Shooter::Shooter(hw_info launchInfo,hw_info liftInfo,hw_info feedInfo) : launcherWheel(launchInfo), angleAdjuster(liftInfo), feed(feedInfo)
{
    updateRegistry.addUpdateFunction(&update_helper, (void*)this);
}

Shooter::~Shooter() {
}

void Shooter::update() {
    switch(currentState)
    {
        case VISION_ANALYSIS:
            doVisionAnalysis();
            break;
        case AIMING:
            doAiming();
            break;
        case SHOOTING:
            doShooting();
            break;
    }
}
void Shooter::doVisionAnalysis() {

    //End Lines
    HorizontalAlignment = false;
    angleSet = false;
}
void Shooter::doAiming() {
    if(!HorizontalAlignment)
    {
        lineUpHorizontal();
    }
    else if(!angleSet)
    {
        setAngleOfAttack();
    }
    else if(angleAdjuster.atAngle())
    {
        currentState = SHOOTING;
        resetShotCount(); //Final line
    }
}
void Shooter::doShooting() {
    if(getShotCount() >= 4)
    {
        currentState = USER_CONTROLLED;
        return;
    }
    shoot();
}
void Shooter::autoShoot() {
    if(currentState == USER_CONTROLLED)
        currentState = VISION_ANALYSIS;
}
void Shooter::setToUserControlled() {
    currentState = USER_CONTROLLED;
}
void Shooter::resetShotCount() {
    launcherWheel.resetFrisbeeCount();
}
unsigned int Shooter::getShotCount() {
    return launcherWheel.getFrisbeeCount();
}
void Shooter::lineUpHorizontal() {
    //todo line up to main target
}
void Shooter::setAngleOfAttack() {
    //todo set angle
}
void Shooter::shoot() {
    if(launcherWheel.atSpeed()) {
        feed.forward();
    }
    else
    {
        feed.stop();
    }
}
static void Shooter::update_helper(void* a) {
    ((Shooter*)a) -> update();
}
#endif
