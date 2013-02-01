#include "autonomous.h"
#include "ports.h"
#include "shooterAim.h"
#include "state.h"
#include "drivetrain.h"
#include <cmath>

bool isLeft;
bool state_changed = false;
int Frisbees = 3;
const int DRIVE_DIST=40;
const int TURN_ANGLE= -34; // negative is clockwise, positive is counter-clockwise
enum auto_states {
	AUTO_DRIVE,
	AUTO_TURN,
	AUTO_AIM,
	AUTO_SHOOT,
	DONE
};

//0 = init drive 
//1 = drive
//2 = init turn
//3 = turn
//4 = init aim
//5 = aim
//6 = init shoot
//7 = shoot

//note : above not entirely accurate

State state(AUTO_DRIVE);

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
        state.set_state(DONE);
        state_changed = true;
    }
}

void aim() {
    std::printf("aiming");
    state.set_state(AUTO_SHOOT);
}

void shoot() {
    std::printf("shooting");
    state.set_state(DONE);
}

void choose_routine(Position pos, Target target){
    if ((pos == Back_Left) || (pos == Front_Left)) {
        isLeft = true;
    }
    if ((pos == Back_Left) || (pos == Back_Right)) {
        state.set_state(AUTO_DRIVE);
        Frisbees = 3;
    } else if ((pos == Front_Left) || (pos == Front_Right)) {		
    	state.set_state(AUTO_TURN);
    }
    state_changed = true;
}
void do_autonomous(){
		if(state.get_state()==AUTO_DRIVE) {
			drive(DRIVE_DIST);
		} else if (state.get_state()==AUTO_TURN){
			if (isLeft == true){
				turn(TURN_ANGLE);
			} else {
				turn(abs(TURN_ANGLE));	
			}
		} else if (state.get_state()==DONE) {
			//Wait(0.015);
		}/* else if (state.get_state()==AUTO_AIM){
			aim(); 
		} else if (state.get_state()==AUTO_SHOOT) {
			shoot();
		}*/	
}
/* THIS CODE BELONGS TO ZACK, PRESUME IT DOESN'T WORK*/ /*oh ya and adrian and swaraj*/
