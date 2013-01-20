#ifndef _612_H
#define _612_H

#include "state.h"

extern State global_state;

enum teleop_state {
    DRIVE, CLIMB, SHOOT_AUTO, SHOOT_MANUAL
};

#endif // _612_H
