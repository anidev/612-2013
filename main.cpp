#include <string>
#include <cmath>
#include <Counter.h>
#include <networktables/NetworkTable.h>

#include "state.h"
#include "states/state_driving.h"
#include "states/state_shooting.h"
#include "states/state_climbing.h"
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
#ifndef Suzie
    led_spike.Set(Relay::kOff);
    ledstrip_spike.Set(Relay::kOff);
#endif
}

void robot_class::AutonomousInit() {
    std::printf("AutonomousInit\n");
#ifndef Suzie
    led_spike.Set(Relay::kForward);
    ledstrip_spike.Set(Relay::kForward);
#endif
    // 0 = Front Right
    // 1 = Back Left
    // 2 = Front Left
    // 3 = Back Right
    Position auto_pos=Back_Left;
    AutoTarget auto_target=Middle_Goal;
    int positionVal=(int)netcom->Autonomous_Position();
    int targetVal=(int)netcom->Autonomous_Target();
    int drivingVal=(int)netcom->Autonomous_BackDriving();
    bool auto_driving=drivingVal==1; // Stationary=0, Driving=1
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
    choose_routine(auto_pos, auto_target, auto_driving);
}

void robot_class::TeleopInit() {
    std::printf("TelopInit\n");
#ifndef Suzie
    led_spike.Set(Relay::kForward);
    ledstrip_spike.Set(Relay::kForward);
#endif
}

void robot_class::DisabledPeriodic() {
}

void robot_class::AutonomousPeriodic() {
    updateRegistry.updateAll();
    do_autonomous();
}

void robot_class::TeleopPeriodic() {
    updateRegistry.updateAll();
    if(global_state.get_state() == DRIVE) 
    {
        driving_state();
        shooting_manual(); // at same time as driving
    }
    else if(global_state.get_state() == SHOOT_AUTO) 
    {
        shooting_auto();
    }
    else if(global_state.get_state() == CLIMBING) 
    {
        climbing_state();
    }
}
void robot_class::TestInit() {
}
void robot_class::TestPeriodic() {
    static float target_speed = 0.0f;
    updateRegistry.updateAll();
    if(gunner_gamepad.GetRawButton(1))
    {
        target_speed = 40.0f;
    }
    else if(gunner_gamepad.GetRawButton(2))
    {
        target_speed = 45.0f;
    }
    else if(gunner_gamepad.GetRawButton(3))
    {
        target_speed = 55.0f;
    }
    else if(gunner_gamepad.GetRawButton(4))
    {
        target_speed = 60.0f;
    }
    if(target_speed!=shooter.getTargetSpeed()) {
        shooter.setSpeed(target_speed);
    }
    netcom->launcher_target_speed(target_speed);
    if(gunner_gamepad.GetRawAxis(2) > 0.5)
        shooter.setFeederForward();
    else if(gunner_gamepad.GetRawAxis(2) < -0.5)
        shooter.setFeederBackward();
}
//the following macro tells the library that we want to generate code
//for our class robot_class
START_ROBOT_CLASS(robot_class);
