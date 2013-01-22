#ifndef PORTS_H
#define PORTS_H

#include <Joystick.h>
#include <RobotDrive.h>

typedef int canport_t;

struct hw_info {
    UINT8 moduleNumber;
    UINT8 channel;
};

extern Joystick left_joystick;
extern Joystick right_joystick;
extern Joystick gunner_joystick;
extern RobotDrive drive_train;

static const hw_info left_front_motor={2,2};
static const hw_info left_rear_motor={2,3};
static const hw_info right_front_motor={1,3};
static const hw_info right_rear_motor={1,4};

#endif
