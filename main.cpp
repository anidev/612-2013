#include <string>
#include <cmath>
#include <Counter.h>
#include <networktables/NetworkTable.h>
#include "state.h"
#include "states/state_driving.h"
#include "states/state_shooting.h"

#include "612.h"
#include "ports.h"
#include "auto_encoders.h"
#include "autonomous.h"
#include "EnhancedJoystick.h"
#include "main.h"
#include "Shooter.h"
#include "feeder.h"

robot_class::robot_class() {
    GetWatchdog().SetEnabled(false);
}

void robot_class::RobotInit() {
    std::printf("RobotInit\n");
    netcom = new NetworkCom();
}

void robot_class::DisabledInit() {
    std::printf("DisabledInit\n");
    led_spike.Set(Relay::kOff);
}

void robot_class::AutonomousInit() {
    std::printf("AutonomousInit\n");
    led_spike.Set(Relay::kForward);
    // 0 = Front Right
    // 1 = Back Left
    // 2 = Front Left
    // 3 = Back Right
    Position auto_pos=Back_Left;
    AutoTarget auto_target=Middle_Goal;
    int positionVal=(int)netcom->Autonomous_Position();
    int targetVal=(int)netcom->Autonomous_Target();
    switch(positionVal) {
    case 0:
        auto_pos=Front_Right;
        std::printf("Selected autonomous: FRONT RIGHT\n");
        break;
    case 1:
        auto_pos=Back_Left;
        std::printf("Selected autonomous: BACK LEFT\n");
        break;
    case 2:
        auto_pos=Front_Left;
        std::printf("Selected autonomous: FRONT LEFT\n");
        break;
    case 3:
        auto_pos=Back_Right;
        std::printf("Selected autonomous: BACK RIGHT\n");
        break;
    }
    switch(targetVal) {
    case 0:
        auto_target=High_Goal;
        std::printf("Selected autonomous: HIGH GOAL\n");
        break;
    case 1:
        auto_target=Middle_Goal;
        std::printf("Selected autonomous: MID GOAL\n");
        break;
    }
    choose_routine(auto_pos, auto_target);
}

void robot_class::TeleopInit() {
    std::printf("TelopInit\n");
    led_spike.Set(Relay::kForward);
}

void robot_class::DisabledPeriodic() {
}

void robot_class::AutonomousPeriodic() {
    updateRegistry.updateAll();
    do_autonomous();
}

void robot_class::TeleopPeriodic() {
    static int counter = 0;
    updateRegistry.updateAll();
    if(counter%25 == 0) {
//        std::printf("Driver operating: %s\n",(driverOperation?"TRUE":"FALSE"));
    }
    counter++;
    if(global_state.get_state() == DRIVE) {
        driving_state();
        shooting_manual(); // at same time as driving
    }
    else if(global_state.get_state() == SHOOT_AUTO) {
        shooting_auto();
    }
}
void robot_class::TestInit() {
}
void robot_class::TestPeriodic() {
//    static F
    updateRegistry.updateAll();
/*    static int counter=0;
    if(counter%10==0) {
        std::printf("feeder speed: %f\n",drive_gamepad.GetRawAxis(1));
    }
    counter++;*/
    if(gunner_gamepad.GetRawAxis(2) > 0.5)
        shooter.setFeederForward();
    else if(gunner_gamepad.GetRawAxis(2) < -0.5)
        shooter.setFeederBackward();
}
//the following macro tells the library that we want to generate code
//for our class robot_class
START_ROBOT_CLASS(robot_class);
