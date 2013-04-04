#include <IterativeRobot.h>
#include <Jaguar.h>
#include <Joystick.h>

#define JOYSTICK
//#define GAMEPAD

class robot_class:public IterativeRobot {
private:
	Jaguar left_front;
	Jaguar left_rear;
	Jaguar right_front;
	Jaguar right_rear;
	RobotDrive drive;
	Joystick controller1;
	Joystick controller2;
public:
	robot_class();
	~robot_class();
	void RobotInit();
	void DisabledInit();
	void AutonomousInit();
	void TeleopInit();
	void DisabledPeriodic();
	void AutonomousPeriodic();
	void TeleopPeriodic();

	static NetworkTable* mainTable;
};
