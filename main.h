#ifndef MAIN_H
#define MAIN_H

#include <IterativeRobot.h>

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
};

#endif
