#ifndef PORTS_H
#define PORTS_H

#include <Joystick.h>

typedef int canport_t;
struct hw_info {
    UINT8 moduleNumber,
    UINT8  channel,
};

extern Joystick left_joystick;
extern Joystick right_joystick;
extern Joystick gunner_joystick;

#endif
