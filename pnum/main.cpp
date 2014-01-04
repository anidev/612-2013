#include <cstdio>
#include <cmath>
#include "612.h"
#include "main.h"
#include "Hardware.h"
#include "Relay.h"
#include "DigitalInput.h"

robot_class* robot=NULL;

robot_class::robot_class()
{
    GetWatchdog().SetEnabled(false);
    //Hardware
    robot=this;
    compressor = new Relay(1,8,Relay::kForwardOnly);
    pnumSwitch =  new DigitalInput(1,2);
}

void robot_class::RobotInit() {
}

void robot_class::DisabledInit() {
    std::printf("disabled init\n");
}

void robot_class::DisabledPeriodic() {
    //Never Put Code Here
}

void robot_class::AutonomousInit() {
}

void robot_class::AutonomousPeriodic() {
}

void robot_class::TeleopInit() {
}

void robot_class::TeleopPeriodic() {
}

void robot_class::TestInit() {
    std::printf("test init\n");
    std::printf("******************Pnum stuff************************\n");
    compressor -> Set(Relay::kForward);
}

void robot_class::TestPeriodic() {
//    engine->getTargetsNow();
    //switch is bool
    /*
    if (pnumSwitch->Get() == 1)
        compressor->Set(Relay::kOn);
    else
        compressor->Set(Relay::kOff);
    */
}

START_ROBOT_CLASS(robot_class);
