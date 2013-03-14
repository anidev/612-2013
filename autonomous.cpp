#include "autonomous.h"
#include "ports.h"
#include "state.h"
#include "drivetrain.h"
#include "lift.h"
#include "shooter.h"
#include "AutoShooter.h"
#include "launcher.h"
#include "autonomous_presets.h"

bool isLeft;
bool isBack; 
bool auto_state_changed = false;
bool shooter_prepped = false;

unsigned int Frisbees = 2;
float Launcher_Speed = 0.4;

const double DRIVE_DIST = 40;
const double FRONT_TURN_ANGLE = -34; // negative is clockwise, positive is counter-clockwise
const double BACK_TURN_ANGLE = -12;
const float HIGH_LIFT_ANGLE = 2.58;     //suzie pot angles
const float LOW_LIFT_ANGLE = 2.14;      //suzie pot angles

enum auto_states {
    AUTO_DRIVE,
    AUTO_TURN,
    AUTO_SHOOT,
    DONE
};

State state(AUTO_DRIVE);
AutoTarget shoot_tar;

void ShooterPrep(double angle, float speed) {
    if (!shooter_prepped) {
        shooter.setSpeed(speed);
        angleAdjuster.set_angle(angle);
        shooter_prepped = true;
    }
}


void drive(double dist /*inches*/) {
    if (auto_state_changed) 
    {
        drive_train.drive(dist);
        auto_state_changed = false;
    }
    else if (drive_train.isFinished()) 
    {
        state.set_state(AUTO_TURN);
        auto_state_changed = true;
    }
}

void turn(double angle) {
    if (auto_state_changed) 
    {
        drive_train.turn(angle);
        auto_state_changed = false;
    }
    else if (drive_train.isFinished()) {
        state.set_state(AUTO_SHOOT);
        auto_state_changed = true;
    }
}

void shoot() {
    if (auto_state_changed) 
    {
        std::printf("shooting\n");
        auto_shoot.AutoShoot();
        auto_state_changed = false;
    }
    else if (auto_shoot.doneShooting()) 
    {
        state.set_state(DONE);
        auto_state_changed = true;
    }
}

void choose_routine(Position pos, AutoTarget target, bool BackDrive){
    auto_state_changed = true;
    shooter_prepped = false;
    shoot_tar = target;
    //check if the robot is on the left
    if ((pos == Back_Left) || (pos == Front_Left))  {
        isLeft = true;
    }
    else 
    {
        isLeft = false;
    }
    //check if the robot is in the back
    if((pos == Back_Left) || (pos == Back_Right)) 
    {
        isBack = true;
            Frisbees = 3;
        if (BackDrive) 
        {
            state.set_state(AUTO_DRIVE);
            if (target == Middle_Goal) 
            {
                ShooterPrep(FrontMiddleLiftAngle,FrontMiddleLauncherSpeed); 
            }
            else 
            {
                ShooterPrep(FrontHighLiftAngle,FrontHighLauncherSpeed);
            }
        }
        else
        {
            state.set_state(AUTO_SHOOT);
            if (target == Middle_Goal) 
            {
                ShooterPrep(BackMiddleLiftAngle,BackMiddleLauncherSpeed); 
            }
            else
            {
                ShooterPrep(BackHighLiftAngle,BackHighLauncherSpeed);
            }
        }
    }
    else if ((pos == Front_Left) || (pos == Front_Right))
    {
        Frisbees = 2;
        state.set_state(AUTO_TURN);
        if (target == Middle_Goal)
        {
            ShooterPrep(FrontMiddleLiftAngle,FrontMiddleLauncherSpeed); 
        }
        else
        {
            ShooterPrep(FrontHighLiftAngle,FrontHighLauncherSpeed);
        }
    }
    /*Shooter prep logic*/
}
void do_autonomous() {
    if (state.get_state()==AUTO_DRIVE) {
	drive(DRIVE_DIST);
    } else if (state.get_state()==AUTO_TURN){
	if (isBack) {
	    if (isLeft){
		turn(BACK_TURN_ANGLE);
	    } else {
		turn(-BACK_TURN_ANGLE);
	    }
	} else {
	    if (isLeft){
		turn(FRONT_TURN_ANGLE);
	    } else {
		turn(-FRONT_TURN_ANGLE);
	    }
	}
    } else if (state.get_state()==AUTO_SHOOT) {
	shoot();
    } else if (state.get_state()==DONE) {
	std:: printf("Autonomous is finished");
    }
}
