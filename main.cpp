#include <string>
#include <cmath>
#include <networktables/NetworkTable.h>
#include "state.h"
#include "states/state_driving.h"
#include "states/state_shooting.h"
#include "states/state_climbing.h"
#include "612.h"
#include "ports.h"
#include "auto_encoders.h"
#include "main.h"
#include "autonomous.h"

robot_class::robot_class() {
    GetWatchdog().SetEnabled(false);
}

void robot_class::RobotInit() {
    std::printf("RobotInit");
    main_table=NetworkTable::GetTable("612");
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
    if(main_table!=NULL) {
        NetworkTable* auto_table=main_table->GetSubTable("Autonomous");
        if(auto_table!=NULL) {
            int positionVal=(int)auto_table->GetNumber("Position");
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
        }
    }
    choose_routine(auto_pos, High_Goal);
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
    updateRegistry.updateAll();
    if(global_state.get_state()==DRIVE) {
        driving_state();
        shooting_manual(); // at same time as driving
    }
    else if(global_state.get_state() == CLIMB) {
        climbing_state();
    }
    else if(global_state.get_state() == SHOOT_AUTO) {
        shooting_auto();
    }
    Wait(0.015); // let the CPU rest a bit
}

//the following macro tells the library that we want to generate code
//for our class robot_class
START_ROBOT_CLASS(robot_class);
