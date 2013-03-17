#include <cmath>
#include "EnhancedRobotDrive.h"
#include "main.h"
#include "updateRegistry.h"
#include "Task.h"
#include "Autonomous.h"
#include "Talon.h"
#include "EnhancedJoystick.h"
#include "EnhancedShooter.h"
//TODO Add Stop Task Autonomous to disableReg

robot_class::robot_class():
        drive_gamepad(1,(void*)this),
        gunner_gamepad(2,(void*)this),
        Autonomous("Auto",(FUNCPTR)&doAutonomous)
{
    GetWatchdog().SetEnabled(false);
    disableRegistry.addUpdateFunction(&disableAuto,(void*)this); // Add Autonomous disable to disableReg
    //Hardware Info
    hw_info left_front_motor  = {2,10};
    hw_info left_rear_motor   = {2,9};
    hw_info right_front_motor = {2,7};
    hw_info right_rear_motor  = {2,8};
    static const unsigned int shooterWheelCanport = 1;
    static const unsigned int shooterLiftCanport = 2;
    hw_info halEffect = {1,3};
    hw_info feeder = {1,1};
    //Hardware
    driveTrain = new EnhancedRobotDrive(new Talon(left_front_motor.moduleNumber,left_front_motor.channel),
                           new Talon(left_rear_motor.moduleNumber,left_rear_motor.channel),
                           new Talon(right_front_motor.moduleNumber,right_front_motor.channel),
                           new Talon(right_rear_motor.moduleNumber,right_rear_motor.channel),(void*)this);
    shooter = new EnhancedShooter(shooterWheelCanport,shooterLiftCanport,feeder,halEffect,(void*)this);
}

void robot_class::RobotInit() {
    enableRegistry.updateAll();
}

void robot_class::DisabledInit() {
    disableRegistry.updateAll();
}

void robot_class::AutonomousInit() {
    //Autonomous.Start((UINT32)this); Todo add to allow autonomous
}

void robot_class::TeleopInit() {
    enableRegistry.updateAll();
}

void robot_class::DisabledPeriodic() {
    //Never Put Code Here
}

void robot_class::AutonomousPeriodic() {
}

void robot_class::TeleopPeriodic() {
    updateRegistry.updateAll();
    driveTrain -> doControls();
    shooter -> doControls();
    
}

void robot_class::TestInit() {
}

void robot_class::TestPeriodic() {
}
//the following macro tells the library that we want to generate code
//for our class robot_class
START_ROBOT_CLASS(robot_class);
