#include "autonomous.h"
#include "ports.h"

/*
READ NOTE AT BOTTOM
*/

void choose_routine() {
	
}

void drive(double dist /*keep in mind that dist is in inches*/) {
	encoders.reset_distance();
	while (encoders.get_distance() < dist) {
		drive_train.TankDrive(1,1); //change the (1,1) to something safer later
	}
	encoders.stop_driving();
}

void turn(double angle) {
	/*
	keep in mind that the angles in use will be calculated with the robot
	facing the 0deg mark. This means that turning to the right will require a negative angle
	and turning to the left will require a positive angle. 
	if the angle is negative, then the motors on the right side of the robot
	will need to be positively powered and the left motors will need to be negatively powered and 
	vice versa if the angle is positive.
	note: get width of robot
	note: this method should be able to calculate the change in angle 
	*/
	double distance = angle / 2.88629075498;
	encoders.reset_distance();
	encoders.stop_driving();
	if (angle > 0) {
		while (encoders.get_distance() < distance) {
			drive_train.TankDrive(-1,1); //change the (1,1) to something safer later
		}
	} else if (angle < 0) {
		while (encoders.get_distance() < distance) {
			drive_train.TankDrive(1,-1); //change the (1,1) to something safer later
		}
	}
}

/*
NOTE: THIS CODE DOES NOT COMPILE. THIS CODE IS NOWHERE NEAR COMPILING. 
MANY MISSING VALUES HERE MUST BE CALCULATED AND THEN PUT INTO THIS CODE.
*/
