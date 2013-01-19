#include <cmath>
#include "state.h"
#include "states/state_driving.h"
#include "states/state_shooting.h"
#include "states/state_climbing.h"
#include "612.h"
#include "main.h"

robot_class::robot_class() {
    GetWatchdog().SetEnabled(false);
}

void robot_class::RobotInit() {
    std::printf("RobotInit");
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
}

void robot_class::AutonomousPeriodic() {
}

void robot_class::TeleopPeriodic() {
    std::printf("TeleopPeriodic");
    if(global_state.get_state()==DRIVE) {
        driving_state();
    } else if(global_state.get_state()==SHOOT) {
        shooting_state();
    } else if(global_state.get_state()==CLIMB) {
        climbing_state();
    }
}

//the following macro tells the library that we want to generate code
//for our class robot_class
START_ROBOT_CLASS(robot_class);
