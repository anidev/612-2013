#ifndef SHOOTERAIM_H
#define SHOOTERAIM_H

#include <vector>
#include <vision.h>

enum shooterAimState {
	userControl,
	targetSelection,
	aiming,
	doneAiming,
	settingSpeed,
	shooting,
};

class ShooterAim {
	private:
	shooterAimState state = userControl;
	vector<target> currentTargets;
	target* mainTarget = NULL;
	bool canUseAutoAim = false; // can we see the targets
	float angle;
	void setMainTarget();
	void doShooting();
	void setAngle();
	void doAiming();

	public:
	ShooterAim();
	~ShooterAim();
	bool isAimed();
	shooterAimState getState();
	float getNeededAngle();
	float getNeededAngle(target &);
	void autoShoot();
	void update();
	
};
#endif
/*		Assumes
 * 1. vision.h has target class
 * 2. shooter has aim_left() aim_right() aim_up() aim_down()
 * 3. vector<target> currentTargets is included in vision class as a protected variable
 * 4. vision class has ShooterAim as friend
 * 5. target has getPriority();
 */
