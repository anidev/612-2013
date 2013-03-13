#ifndef _612_H
#define _612_H

#include <cmath>
#include <networktables/NetworkTable.h>
#include "state.h"
#include "updateRegistry.h"

//#define Suzie // Comment out to change to current Bot

extern State global_state;
extern UpdateRegistry updateRegistry;
extern bool driverOperation;

enum teleop_state {
    DRIVE, SHOOT_AUTO, CLIMBING
};

static const double M_PI=3.14159256359;
static const float JOY_THRESHOLD=0.08;

inline bool joyzero(float input) {
    return (std::fabs(input)<JOY_THRESHOLD);
}

#endif // _612_H
