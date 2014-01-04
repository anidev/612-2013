#ifndef MAIN_H
#define MAIN_H

#include <Vision/AxisCamera.h>
#include <Vision/HSLImage.h>
#include <IterativeRobot.h>
#include "DigitalInput.h"
#include "Relay.h"

class EnhancedRobotDrive;
class EnhancedShooter;
class DataLogger;

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

    DigitalInput* pnumSwitch;
    Relay* compressor;
private:
};

#endif
