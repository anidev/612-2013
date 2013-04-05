#include <IterativeRobot.h>
#include <Jaguar.h>
#include <Servo.h>
#include <Joystick.h>
#include <RobotDrive.h>

//#define JOYSTICK
#define GAMEPAD

class robot_class:public IterativeRobot {
private:
	Jaguar left_front;
	Jaguar left_rear;
	Jaguar right_front;
	Jaguar right_rear;
	RobotDrive drive;
	Joystick controller1;
	Joystick controller2;
	Servo shift_left;
	Servo shift_right;
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
};
