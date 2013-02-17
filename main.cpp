#include <string>
#include <cmath>
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

void driver_check_update(void* dummy) {
/*    if(std::fabs(right_joystick.GetY())>JOY_THRESHOLD) {
        driverOperation=true;
        return;
    }
    if(std::fabs(left_joystick.GetY())>JOY_THRESHOLD) {
        driverOperation=true;
        return;
    }
    if(left_joystick.GetRawButton(1)&&std::fabs(left_joystick.GetX())>JOY_THRESHOLD) {
        driverOperation=true;
        return;
    }*/

    if(!joyzero(drive_gamepad.GetRawAxis(2))||!joyzero(drive_gamepad.GetRawAxis(4))) { // axis controls
        driverOperation=true;
        return;
    }
    if(drive_gamepad.GetRawButton(7)||drive_gamepad.GetRawButton(8)) {
        driverOperation=true;
        return;
    }
    driverOperation=false;
}

robot_class::robot_class() {
    GetWatchdog().SetEnabled(false);
}

void robot_class::RobotInit() {
    std::printf("RobotInit");
    netcom=new NetworkCom();
    updateRegistry.addUpdateFunction(&driver_check_update,NULL);
}

void robot_class::DisabledInit() {
    std::printf("DisabledInit");
}

void robot_class::AutonomousInit() {
    std::printf("AutonomousInit");
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
    std::printf("TelopInit");
}

void robot_class::DisabledPeriodic() {
//    std::string key("fromrobottest");
//    main_table->PutNumber(key,612.0);
}

void robot_class::AutonomousPeriodic() {
    updateRegistry.updateAll();
    do_autonomous();
}

void robot_class::TeleopPeriodic() {
    static int counter=0;
    updateRegistry.updateAll();
    if(counter%20==0) {
//        std::printf("Driver operating: %s\n",(driverOperation?"TRUE":"FALSE"));
    }
    counter++;
    if(global_state.get_state()==DRIVE) {
        driving_state();
        shooting_manual(); // at same time as driving
    }
    else if(global_state.get_state() == SHOOT_AUTO) {
        shooting_auto();
    }
}
void TestInit() {   
}
void TestPeriodic() {
    updateRegistry.updateAll();
    if(std::fabs(drive_gamepad.GetRawAxis(1)) > 0.05)
    {
        shooter.setFeederForward();
    }
    else
    {
        shooter.setFeederStop();
    }
    if(std::fabs(drive_gamepad.GetRawAxis(1)) > 0.05)
    {
        shooter.setSpeed(drive_gamepad.GetRawAxis(1));
    }
    else
    {
        shooter.setSpeed(0.0);
    }
}
//the following macro tells the library that we want to generate code
//for our class robot_class
START_ROBOT_CLASS(robot_class);
