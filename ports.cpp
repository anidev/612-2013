#include <Joystick.h>
#include <Jaguar.h>
#include <RobotDrive.h>
#include "ports.h"
#include "launcher.h"
#include "auto_encoders.h"
#include "shifter.h"
#include "612.h"

UpdateRegistry updateRegistry; // Must be first constructed
EnhancedJoystick left_joystick   (1);
EnhancedJoystick right_joystick  (2);
EnhancedJoystick gunner_joystick (3);

shifter shift(side1,side2);
