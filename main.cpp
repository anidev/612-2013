#include <cmath>
#include "EnhancedRobotDrive.h"
#include "main.h"
#include "updateRegistry.h"
#include "Talon.h"
#include "EnhancedJoystick.h"
#include "EnhancedShooter.h"
#include "dataLogger.h"
#include "Hardware.h"
#include "Controls.h"
#include "Relay.h"

const float AUTO_ANGLES[] = {30.5f,24.0f};
static const float AUTO_SPEED = 0.0f;
float AUTO_ANGLE = 0.0f;

robot_class::robot_class():
        drive_gamepad(1,(void*)this),
        gunner_gamepad(2,(void*)this),
        LEDring(ledring.moduleNumber,ledring.channel),
        autoSwitch(AutoSelectSwitch.moduleNumber,AutoSelectSwitch.channel)
{
    curState = NORMAL;
    GetWatchdog().SetEnabled(false);
    //Hardware
    driveTrain = new EnhancedRobotDrive(new Talon(left_front_motor.moduleNumber,left_front_motor.channel),
                           new Talon(left_rear_motor.moduleNumber,left_rear_motor.channel),
                           new Talon(right_front_motor.moduleNumber,right_front_motor.channel),
                           new Talon(right_rear_motor.moduleNumber,right_rear_motor.channel),(void*)this);
    shooter = new EnhancedShooter(shooterWheel,WHalEffectInfo,shooterLift,feederInfo,FHalEffectInfo,ledstrip_spike,(void*)this);
    drive_gamepad.addBtn(DRIVER_BTN_CLIMBING_STATE,&setClimbing,(void*)this);
    drive_gamepad.addBtn(DRIVER_BTN_NORMAL_STATE,&setNormal,(void*)this);
    dataLogger = new DataLogger(shooter,(void*)this);
}

void robot_class::RobotInit() {
    driveTrain->shiftHighGear((void*)driveTrain);
}

void robot_class::DisabledInit() {
    disableRegistry.updateAll();
}

void robot_class::AutonomousInit() {
    driveTrain->SetSafetyEnabled(false);
    unsigned int choice = 0;
    if(autoSwitch.Get())//determining pot angles
        choice = 1;
    std::printf("switch: %d\n",autoSwitch.Get());
    AUTO_ANGLE = AUTO_ANGLES[choice];/*choices are at the top*/
    shooter -> setAngle(AUTO_ANGLE); /*and deterined by autoSwitch*/
    shooter -> wheelForward = true;
    shooter -> setSpeed(AUTO_SPEED);
}

void robot_class::TeleopInit() {
    shooter->stopWheel();      // stop the shooter wheel after autonomous period is over
                               // feeder will automatically stop at hall effect sensor
    driveTrain->SetSafetyEnabled(true);
	LEDring.Set(Relay::kForward);
}

void robot_class::DisabledPeriodic() {
    //Never Put Code Here
}

void robot_class::AutonomousPeriodic() {
    //continuesly checks if autonomous done setting the speed of the shooter
    //wheel and the pot angle, when it is done it continuesly moves the feeder
    updateRegistry.updateAll();
    if(shooter -> atSpeed(AUTO_SPEED) && shooter -> atAngle(AUTO_ANGLE))
    {
        shooter -> setFeeder(EnhancedShooter::FORWARD);
    }
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
void robot_class::setClimbing(void* o) {
    (((robot_class*)o) -> curState) = CLIMBING;
}
void robot_class::setNormal(void* o) {
    (((robot_class*)o) -> curState) = NORMAL;
}
//the following macro tells the library that we want to generate code
//for our class robot_class
START_ROBOT_CLASS(robot_class);
