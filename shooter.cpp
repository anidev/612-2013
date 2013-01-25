#if 0
#include "shooter.h"

Shooter::Shooter(hw_info launchInfo,hw_info liftInfo,hw_info feedInfo) : launcherWheel(launchInfo), angleAdjuster(liftInfo), feed(feedInfo)
{

}

Shooter::~Shooter() {
}

void Shooter::update() {
    switch(currentState)
    {
        case visionAnalysis:
            doVisionAnalysis();
	    break;
        case aiming:
            doAiming();
	    break;
        case shooting:
            doShooting();
	    break;
    }
}
void Shooter::doAiming() {
}
void Shooter::doShooting() {
    if(launcherWheel.atSpeed()) {
        feed.forward();
    }
    else
    {
        feed.stop();
    }
}
void Shooter::doVisionAnalysis() {
}
void Shooter::doUserControlled() {
}
void Shooter::autoShoot() {
    if(currentState == userControlled)
        currentState = visionAnalysis;
}
void Shooter::setToUserControlled() {
    currentState = userControlled;
}
void Shooter::resetShotCount() {
    launcherWheel.resetFrisbeeCount();
}
unsigned int Shooter::getShotCount() {
    return launcherWheel.getFrisbeeCount();
}
#endif
