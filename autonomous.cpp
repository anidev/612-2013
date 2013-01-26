#include "autonomous.h"
#include "ports.h"

void choose_routine(int routine, int goal ) {
    switch (routine) {
        case 1:
            front_left(goal);
            break;
        case 2:
            front_right(goal);
            break;
        case 3:
            back_left(goal);
            break;
        case 4:
            back_right(goal);
            break;
        default:
            /*parse the errors some way*/
            break;
    }
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
    double distance = angle / 3.07912798856;
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

void front_left(int goal) {
    switch (goal) {
        case 2:
            turn(9);
            //shooting function
            break;
        case 3:
            turn(-29);
            break;
        default:
            printf("incorrect goal parameter");
            break;
    }
}
void front_right(int goal) {
    switch (goal) {
        case 2:
            turn(-9);
            //shooting function
            break;
        case 3:
            turn(29);
            //shooting function
            break;
        default:
            printf("incorrect goal parameter");
            break;
    }
}
void back_left(int goal) {
    switch (goal) {
        case 2:
            drive(119);
            turn(9);
            //shooting function
            break;
        case 3:
            drive(119);
            turn(-29);
            //shooting function
            break;
        default:
            printf("incorrect goal parameter");
            break;
    }
}

void back_right(int goal) {
    switch (goal) {
        case 2:
            drive(119);
            turn(-9);
            //shooting function
            break;
        case 3:
            drive(119);
            turn(29);
            //shooting function
            break;
        default:
            printf("incorrect goal parameter");
            break;
    }
}

