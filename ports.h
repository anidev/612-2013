#ifndef PORTS_H
#define PORTS_H

#include <Joystick.h>
#include <RobotDrive.h>
#include "EnhancedJoystick.h"

class auto_encoders;
class shifter;

typedef int canport_t;

struct hw_info {
    UINT8 moduleNumber;
    UINT8 channel;
};

extern Joystick left_joystick;
extern EnhancedJoystick right_joystick;
extern EnhancedJoystick gunner_joystick;
extern RobotDrive drive_train;
extern auto_encoders encoders;
static const hw_info side1 = {1,6};
static const hw_info side2 = {2,4};
extern shifter shift;
//Drive Motors
static const hw_info left_front_motor  = {2,2};
static const hw_info left_rear_motor   = {2,3};
static const hw_info right_front_motor = {1,3};
static const hw_info right_rear_motor  = {1,4};
//Encoders
static const hw_info right_encoder1 = {1, 1};
static const hw_info right_encoder2 = {1, 2};
static const hw_info left_encoder1  = {2, 4};
static const hw_info left_encoder2  = {2, 5};
#endif
