#ifndef PORTS_H
#define PORTS_H

#include <Joystick.h>
#include <RobotDrive.h>

class auto_encoders;

typedef int canport_t;

struct hw_info {
    UINT8 moduleNumber;
    UINT8 channel;
};

extern Joystick left_joystick;
extern Joystick right_joystick;
extern Joystick gunner_joystick;
extern RobotDrive drive_train;
extern auto_encoders encoders;

static const hw_info left_front_motor={2,2};
static const hw_info left_rear_motor={2,3};
static const hw_info right_front_motor={1,3};
static const hw_info right_rear_motor={1,4};
static const hw_info right_encoder1 = {1, 1};
static const hw_info right_encoder2 = {1, 2};
static const hw_info left_encoder1 = {2, 4};
static const hw_info left_encoder2 = {2, 5};

#endif
