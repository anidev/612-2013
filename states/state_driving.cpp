#include <RobotDrive.h>
#include <Timer.h>
#include "../ports.h"
#include "../auto_encoders.h"
#include "state_driving.h"
#include "../shifter.h"

void driving_state() {
    float left_axis = left_joystick.GetY ();
    float right_axis = right_joystick.GetY ();
    if (left_joystick.GetRawButton(6)) {
        encoders.reset_distance();
    }
    if (left_joystick.GetRawButton(1)) {
        drive_train.ArcadeDrive(left_joystick);
    } else {
        drive_train.TankDrive(left_axis, right_axis);
    }
    if(gunner_joystick.GetRawButton(7))
    {
        
        if(shift.cur_gear == shifter::LOW && previousState == false)
        {
            shift.set(shifter::HIGH);
        }
        else if(previousState == false)
        {
            shift.set(shifter::LOW);
        }
        previousState = true;
    }
    else
        previousState = false;
    shift.update();
}
