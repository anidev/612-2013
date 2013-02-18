#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "auto_encoders.h"
#include "drivetrain.h"
#include <Encoder.h>

enum Position {Back_Left, Back_Right, Front_Left, Front_Right}; 
enum AutoTarget {Middle_Goal, High_Goal};

static void choose_routine(Position, AutoTarget);
static void do_autonomous();

static void drive();
static void turn();
static void shoot();

#endif
