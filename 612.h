#ifndef 612_H
#define 612_H

#include "state.h"

extern State global_state;

enum teleop_state {
    DRIVE,
    SHOOT,
    CLIMB
};

#endif // _612_H
