#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "auto_encoders.h"
#include "drivetrain.h"
#include <Encoder.h>

enum Position {Back_Left, Back_Right, Front_Left, Front_Right}; 
enum AutoTarget {Middle_Goal, High_Goal};

void choose_routine(Position, AutoTarget);
void do_autonomous();

void drive();
void turn();
void shoot();
void lift();

#endif
