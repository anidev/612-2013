#include <IterativeRobot.h>
#include <Jaguar.h>
#include <Talon.h>
#include <Encoder.h>
#include <Relay.h>
#include <PWM.h>
#include <Joystick.h>
#include <AnalogChannel.h>
#include <Task.h>
#include <Counter.h>
#include <DigitalInput.h>
#include <networktables/NetworkTable.h>

class robot_class:public IterativeRobot {
private:
//	Jaguar launcher;
//	Jaguar feeder;
//	Joystick joy;
//	Joystick joy2;
//	Encoder encoder;
//	Relay ledgreen;
//	Jaguar ledred;
//	Task visionTask;
	Counter launcherSensor;
//	NetworkTable* gunnerTable;
	bool usinggreen;
	bool usingred;
	bool usingboth;
	bool pressed6;
	bool pressed7;
public:
	robot_class();
	~robot_class();
	void RobotInit();
	void DisabledInit();
	void TeleopInit();
	void TeleopPeriodic();

	static NetworkTable* mainTable;
};
