#ifndef MAIN_H
#define MAIN_H

#include <IterativeRobot.h>
#include "updateRegistry.h"
#include "EnhancedJoystick.h"
class EnhancedRobotDrive;
class EnhancedShooter;
class robot_class : public IterativeRobot {
public:
    robot_class();

    void RobotInit();
    void DisabledInit();
    void AutonomousInit();
    void TeleopInit();
    void TestInit();
    
    void DisabledPeriodic();
    void AutonomousPeriodic();
    void TeleopPeriodic();
    void TestPeriodic();
    
    UpdateRegistry disableRegistry;
    UpdateRegistry enableRegistry;
    UpdateRegistry updateRegistry;
    EnhancedJoystick drive_gamepad; //1
    EnhancedJoystick gunner_gamepad; //2
    Task Autonomous;
    //Hardware Info
    struct hw_info {
        UINT8 moduleNumber;
        UINT8 channel;
    };
    EnhancedRobotDrive* driveTrain;
    EnhancedShooter* shooter;
};

#endif
