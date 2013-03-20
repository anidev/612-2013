#ifndef MAIN_H
#define MAIN_H

#include <IterativeRobot.h>
#include "updateRegistry.h"
#include "EnhancedJoystick.h"

class EnhancedRobotDrive;
class EnhancedShooter;

class robot_class : public IterativeRobot {
public:
    enum state {
        CLIMBING,
        NORMAL
    } curState;
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
    UpdateRegistry updateRegistry;
    EnhancedJoystick drive_gamepad; //1
    EnhancedJoystick gunner_gamepad; //2
    EnhancedRobotDrive* driveTrain;
    EnhancedShooter* shooter;
private:
    static const float AUTO_SPEED = 60.0f;
    static const float AUTO_ANGLE = 27.0f;
    static void setClimbing(void*);
    static void setNormal(void*);
};

#endif
