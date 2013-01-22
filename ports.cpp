#include <Joystick.h>
#include <Jaguar.h>
#include <RobotDrive.h>
#include "ports.h"
#include "Launcher.h"

Joystick left_joystick  (1);
Joystick right_joystick (2);
Joystick gunner_joystick(3);
auto_encoders encoders (left_encoder1, right_encoder1, left_encoder2, right_encoder2);

Jaguar left_front_jag(left_front_motor.moduleNumber,left_front_motor.channel);
Jaguar left_rear_jag(left_rear_motor.moduleNumber,left_rear_motor.channel);
Jaguar right_front_jag(right_front_motor.moduleNumber,right_front_motor.channel);
Jaguar right_rear_jag(right_rear_motor.moduleNumber,right_rear_motor.channel);

RobotDrive drive_train(left_front_jag,left_rear_jag,right_front_jag,right_rear_jag);
