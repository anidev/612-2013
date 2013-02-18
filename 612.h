#ifndef _612_H
#define _612_H

#include <cmath>
#include <networktables/NetworkTable.h>
#include "state.h"
#include "updateRegistry.h"

//#define Suzie // Comment Out to change to current Bot

extern State global_state;
extern UpdateRegistry updateRegistry;
extern bool driverOperation;

enum teleop_state {
    DRIVE, SHOOT_AUTO
};

<<<<<<< HEAD
static const double M_PI=3.14159256359;
static const float JOY_THRESHOLD=0.08;
=======
static const double M_PI = 3.14159256359;
static const float JOY_THRESHOLD=0.05;
>>>>>>> eab6503e44d2c00d597b972acc6c3a51efb7b743

inline bool joyzero(float input) {
    return (std::fabs(input)<JOY_THRESHOLD);
}

#endif // _612_H
