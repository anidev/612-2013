#include <Joystick.h>
#include <Jaguar.h>
#include <RobotDrive.h>
#include "ports.h"
#include "launcher.h"
#include "auto_encoders.h"
#include "drivetrain.h"
#include "shifter.h"
#include "lift.h"
#include "shooter.h"
#include "612.h"

UpdateRegistry updateRegistry; // Must be first constructed
EnhancedJoystick left_joystick (1);
EnhancedJoystick right_joystick (2);
EnhancedJoystick gunner_joystick (3);

drivetrain_info dinfo={left_front_motor,left_rear_motor,right_front_motor,right_rear_motor};
encoders_info einfo={left_encoder1,left_encoder2,right_encoder1,right_encoder2};
DriveTrain drive_train(dinfo,einfo);
Shooter shooter(launcher_wheel_1, launcher_wheel_2, launcher_sensor, feeder_1, feeder_2);


shifter shift(side1,side2);

Lift angleAdjuster(lift_motor,launch_angle_pot);

