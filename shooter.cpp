#include "shooter.h"

void Shooter::update() {
	switch(currentState) 
	{
		case visionAnalysis:
			doVisionAnalysis();
		case aiming:
			doAiming();
		case shooting:
			doShooting();
	}
}
void Shooter::doAiming();
void Shooter::doShooting() {
	if(launcherWheel.atSetSpeed())
		feed.forward();
	else
		feed.stop();
}
void Shooter::doVisionAnalysis();
void Shooter::doUserControlled();
Shooter::Shooter(hw_info launcherInfo,hw_info liftInfo) {
	launcherWheel(launcherInfo);
	angleAdjuster() 
}
Shooter::~Shooter() {
	delete launcherWheel;
	delete feed;
	delete angleAdjuster;
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
