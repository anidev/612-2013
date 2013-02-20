#include "autonomous.h"
#include "ports.h"
#include "state.h"
#include "drivetrain.h"
#include "lift.h"
#include "shooter.h"
#include "AutoShooter.h"
#include "launcher.h"

bool isLeft;
bool auto_state_changed = false;
bool shooter_prepped = false;
bool lift_set = false;
bool angle_set = false;

int Frisbees = 3;
float Launcher_Speed = 0.4;

const int DRIVE_DIST = 40;
const int TURN_ANGLE = -34; // negative is clockwise, positive is counter-clockwise
const float HIGH_LIFT_ANGLE = 30;
const float LOW_LIFT_ANGLE = 26;

enum auto_states {
    AUTO_DRIVE,
    AUTO_TURN,
    AUTO_SHOOT,
    DONE
};

State state(AUTO_DRIVE);
AutoTarget shoot_tar;

void ShooterPrep(AutoTarget target) {
    if (auto_state_changed && !shooter_prepped) {
	if (shooter.getCurrentSpeed() < 1.0) {
	    shooter.setSpeed(Launcher_Speed);
	    lift_set = true;
	}
	if (target == High_Goal) {
	    angleAdjuster.set_angle(HIGH_LIFT_ANGLE); 
	    angle_set = true;
	} else if (target == Middle_Goal) {
	    angleAdjuster.set_angle(LOW_LIFT_ANGLE); 
	    angle_set = true;
	}
	if (lift_set && angle_set) {
	    shooter_prepped = true;
	}
	auto_state_changed = false;
    }
    else if (((angleAdjuster.get_current_angle() == HIGH_LIFT_ANGLE) || (angleAdjuster.get_current_angle() == LOW_LIFT_ANGLE)) && (shooter.getCurrentSpeed()==Launcher_Speed)) {
	auto_state_changed = true;
    }
}


void drive(double dist /*inches*/) {
    if (auto_state_changed) {
        drive_train.drive(dist);
        auto_state_changed = false;
    }
    else if (drive_train.isFinished()) {
        state.set_state(AUTO_TURN);
        auto_state_changed = true;
    }
}

void turn(double angle) {
    if (auto_state_changed) {
        drive_train.turn(angle);
        auto_state_changed = false;
    }
    else if (drive_train.isFinished()) {
        state.set_state(AUTO_SHOOT);
        auto_state_changed = true;
    }
}

void shoot() {
    std::printf("shooting");
    if (auto_state_changed) {
        auto_shoot.AutoShoot();
        auto_state_changed = false;
    } else if (auto_shoot.doneShooting()) {
        state.set_state(DONE);
        auto_state_changed = true;
    }
}

void choose_routine(Position pos, AutoTarget target){
    auto_state_changed = true;
    shoot_tar = target;
    if ((pos == Back_Left) || (pos == Front_Left)) {
        isLeft = true;
    }
    else
    {
        isLeft = false;
    }
    if((pos == Back_Left) || (pos == Back_Right)) {
        Frisbees = 3;
    }
    else
    {
        Frisbees = 2;
    }
    if (target==Middle_Goal) {
        state.set_state(AUTO_SHOOT);
    }
    if ((pos == Back_Left) || (pos == Back_Right)) {
        state.set_state(AUTO_DRIVE);
        Frisbees = 3;
    } else if ((pos == Front_Left) || (pos == Front_Right)) {
        state.set_state(AUTO_TURN);
    }
}
void do_autonomous() {
    if (!shooter_prepped) {
	ShooterPrep(shoot_tar);
    }
    else if (state.get_state()==AUTO_DRIVE) {
        drive(DRIVE_DIST);
    } else if (state.get_state()==AUTO_TURN){
        if (isLeft == true){
            turn(TURN_ANGLE);
        } else {
            turn(-TURN_ANGLE);
        }
    } else if (state.get_state()==AUTO_SHOOT) {
        shoot();
    } else if (state.get_state()==DONE) {
        std:: printf("Autonomous is finished");
    }
}

