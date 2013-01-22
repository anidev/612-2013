#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "auto_encoders.h"
#include <Encoder.h>
#include "ports.h"

auto_encoder drive_encoder = new auto_encoder(/*add parameters corresponding to the encoders*/);
void choose_routine(/*add parameter corresponding to pressed button*/);
void drive();
void turn();

#endif
