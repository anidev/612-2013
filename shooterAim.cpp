#if 0
#include "ShooterAim.h"
#include "ports.h"

ShooterAim::ShooterAim() {
}
ShooterAim::~ShooterAim() {
	delete[mainTarget];
}
bool ShooterAim::isAimed() {
	if(state == doneAiming)
		return true;
	return false;
}
shooterAimState ShooterAim::getState() { return state; }
float ShooterAim::getNeededAngle() {
	
}
float ShooterAim::getNeededAngle(target &inputTarget) {
	
}
void ShooterAim::autoShoot() {
	if(state == userControl)
		state = targetSelection;
}
void ShooterAim::update() {
	if((abs(leftJoystick.getX()) > 0.1)||(abs(leftJoystick.getX()) > 0.1)||(abs(leftJoystick.getX()) > 0.1))
		state = userControl;
	switch state {
		case targetSelection:
			setMainTarget();
		case aiming:
			doAiming();
		case doneAiming:
			setAngle();
		case settingSpeed:
			doShooting();
	}
}
void ShooterAim::setMainTarget() {
	//Assumes Target has getPriority
	if(currentTargets.size() > 0)
	{
		mainTarget = &CurrentTargets.at(0);
		for(int x = 0; x < currentTargets.size(); x++)
		{
			if((currentTargets.at(x)).getPriority() > mainTarget->getPriority())
				mainTarget = &(currentTargets.at(x));
		}
	}
	else
	{
		mainTarget = NULL;
	}
	state = aiming;
}
void ShooterAim::doShooting() {
	state = shooting;
	shooter.setAngle(angle);
	shooter.start();
	if(shooter.atSetSpeed() && shooter.atSetAngle())
		shoot();
}
void shooterAim::setAngle() {
	float groundDistance = mainTarget->getGroundDistance();
	float heightDifference = mainTarget->getHeight - trajectory::ROBOTHEIGHT;
	if(heightDifference > 0)
		angle = standardTrajectory(groundDistance,heightDifference);
}
#endif
