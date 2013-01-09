#ifndef INC_MAIN_H_INC
#define INC_MAIN_H_INC

#include <IterativeRobot.h>
#include <RobotDrive.h>

class robot_class : public IterativeRobot {
public:
    robot_class();

    void RobotInit();
    void DisabledInit();
    void AutonomousInit();
    void TeleopInit();
    
    void DisabledPeriodic();
    void AutonomousPeriodic();
    void TeleopPeriodic();
};

#endif
