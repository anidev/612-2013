#include <Joystick.h>
#include <Jaguar.h>
#include <RobotDrive.h>
#include <Counter.h>
#include "ports.h"
#include "launcher.h"
#include "auto_encoders.h"
#include "drivetrain.h"
#include "shifter.h"
#include "lift.h"
#include "shooter.h"
#include "EnhancedJoystick.h"
#include "AutoShooter.h"
#include "612.h"
#include "NetworkCom.h"
#include "dataLogger.h"


#ifndef Suzie
Relay led_spike(led.moduleNumber,led.channel);
Relay ledstrip_spike(ledstrip.moduleNumber,ledstrip.channel);
#endif

UpdateRegistry updateRegistry; // Must be first constructed
EnhancedJoystick drive_gamepad   (1);
EnhancedJoystick gunner_gamepad  (2);
drivetrain_info dinfo={left_front_motor,left_rear_motor,right_front_motor,right_rear_motor};
encoders_info einfo={left_encoder1,left_encoder2,right_encoder1,right_encoder2};
DataLogger logger;
DriveTrain drive_train(dinfo,einfo,side1,side2);
#ifdef Suzie
    Shooter shooter(launcher_wheel_1, launcher_wheel_2, launcher_sensor, feeder_1, feeder_2);
    Lift angleAdjuster(lift_motor,launch_angle_pot);
#else
    Shooter shooter(launcher_wheel, launcher_sensor, feeder_belt, feeder_sensor, IR_sensor);
    Lift angleAdjuster(lift_canJag);
#endif
AutoShooter auto_shoot(shooter); // Must be after #defines
NetworkCom* netcom;
