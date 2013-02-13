#include "autonomous.h"
#include "ports.h"
#include "state.h"
#include "drivetrain.h"
#include "lift.h"
#include "shooter.h"
#include "AutoShooter.h"

bool isLeft;
bool state_changed = false;
int Frisbees = 2;
const int DRIVE_DIST=40;
const int TURN_ANGLE= -34; // negative is clockwise, positive is counter-clockwise
const int HIGH_LIFT_ANGLE = 30;
const int LOW_LIFT_ANGLE = 26;
enum auto_states {
    AUTO_DRIVE,
    AUTO_TURN,
    AUTO_SHOOT,
    DONE
};

State state(AUTO_DRIVE);
AutoTarget shoot_tar;

void lift(AutoTarget target) {
    if (state_changed) {
        if (target == High_Goal) {
            angleAdjuster.set_angle(HIGH_LIFT_ANGLE); /*other angle*/
        } else if (target == Middle_Goal) {
            angleAdjuster.set_angle(LOW_LIFT_ANGLE); /*other angle*/
        }
        state_changed = false;
    } else if (angleAdjuster.at_angle()) {
        state.set_state(AUTO_DRIVE);
        state_changed = true;
    }
}

void drive(double dist /*keep in mind that dist is in inches*/) {
    if (state_changed) {
        drive_train.drive(dist);
        state_changed = false;
    }
    else if (drive_train.isFinished()) {
        //disable the drive train
        state.set_state(AUTO_TURN);
        state_changed = true;
    }
}

void turn(double angle) {
    if (state_changed) {
        drive_train.turn(angle);
        state_changed = false;
    }
    else if (drive_train.isFinished()) {
        //disable the drive train
        state.set_state(AUTO_SHOOT);
        state_changed = true;
    }
}

void shoot() {
    std::printf("shooting");
    if (state_changed) {
        auto_shoot.AutoShoot();
        state_changed = false;
    } else if (auto_shoot.doneShooting()) {
        state.set_state(DONE);
        state_changed = true;
    }
}

void choose_routine(Position pos, AutoTarget target){
    state_changed = true;
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
    lift(shoot_tar);
    if (state.get_state()==AUTO_DRIVE) {
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
/* THIS CODE BELONGS TO ZACK, PRESUME IT DOESN'T WORK*/ /*oh ya and adrian and swaraj*/

