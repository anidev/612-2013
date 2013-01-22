#include "shooter.h"

launcher launcherWheel;
lift angleAdjuster;
feeder feed;
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
Shooter::Shooter() {
	launcherWheel = new Launcher(); // set depending on shooter Parameters
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
