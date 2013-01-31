#include <string>
#include <cmath>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableMode.h>
#include <networktables2/NetworkTableNode.h>
#include <networktables/NetworkTableProvider.h>
#include <networktables2/thread/DefaultThreadManager.h>
#include "state.h"
#include "states/state_driving.h"
#include "states/state_shooting.h"
#include "states/state_climbing.h"
#include "612.h"
#include "ports.h"
#include "auto_encoders.h"
#include "main.h"

robot_class::robot_class() {
    GetWatchdog().SetEnabled(false);
}

void robot_class::RobotInit() {
    std::printf("RobotInit");
//    DefaultThreadManager threadManager;
//    NetworkTableNode* node=NetworkTableMode::Client.CreateNode("10.6.12.1",NetworkTable::DEFAULT_PORT,threadManager);
//    NetworkTableProvider provider(&node);
//    main_table=NetworkTable::GetTable("datatable");
}

void robot_class::DisabledInit() {
    std::printf("DisabledInit");
}

void robot_class::AutonomousInit() {
    std::printf("AutonomousInit");
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
