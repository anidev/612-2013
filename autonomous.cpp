#include "autonomous.h"
#include "ports.h"
#include "shooterAim.h"
#include "state.h"
#include "drivetrain.h"
#include <cmath>

bool isLeft;
int Frisbees = 3;
const int DRIVE_DIST=119;
const int TURN_ANGLE= -29; // negative is clockwise, positive is counter-clockwise
enum auto_states {
	AUTO_DRIVE,
	AUTO_TURN,
	AUTO_AIM,
	AUTO_SHOOT
};

State state(AUTO_DRIVE);

void drive(double dist /*keep in mind that dist is in inches*/) {
	drive_train.drive(dist);
	if (drive_train.isFinished()) {
		state.set_state(AUTO_TURN);
	}
}

void turn(double angle) {
    drive_train.turn(angle);
}

void choose_routine(Position pos, Target target){
	if ((pos == Back_Left) || (pos == Front_Left)) {
		isLeft = true;
	}
    if ((pos == Back_Left) || (pos == Back_Right)) {
		state.set_state(AUTO_DRIVE);
    } else if ((pos == Front_Left) || (pos == Front_Right)) {
    	state.set_state(AUTO_TURN);
    } 
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
	} else if (state.get_state()==AUTO_AIM){
		/*
		aim();
		*/
	} else if (state.get_state()==AUTO_SHOOT) {
		/*
		while (Frisbees > 0) {
			shoot();
			Frisbees-=1;
		}
		*/
	}
}
	
	
	
/* THIS CODE BELONGS TO ZACK, PRESUME IT DOESN'T WORK*/ /*oh ya and adrian and swaraj*/
