#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "auto_encoders.h"
#include <Encoder.h>
#include "ports.h"

void choose_routine(int,int);
void drive();
void turn();
//subroutines
void front_left(int);
void front_right(int);
void back_left(int);
void back_right(int);

#endif
