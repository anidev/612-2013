#include <cmath>
#include <AnalogChannel.h>
#include "lift.h"
#include "ports.h"

Lift::Lift(hw_info jagInfo,hw_info potInfo) : 
liftMotor(jagInfo.moduleNumber,jagInfo.channel),
pot(potInfo.moduleNumber,potInfo.channel)
{
    updateRegistry.addUpdateFunction(&updateHelper,(void*)this);
    manual = true;
}

Lift::~Lift() {
}

void Lift::lift_up() {
    manual = true;
    set_direction(1);
}

void Lift::lift_down() {
    manual = true;
    set_direction(-1);
}

void Lift::lift_stop() {
    manual = true;
    set_direction(0);
}

void Lift::set_angle(float new_angle) {
    manual = false;
    target_angle = new_angle;
}

float Lift::get_current_angle() {
    return potToAngle(pot.GetAverageVoltage());
}

float Lift::get_target_angle() {
    return target_angle;
}

bool Lift::at_angle() {
    if(fabs(get_current_angle()-target_angle)<AT_ANGLE_TOLERANCE) {
        return true;
    }
    return false;
}

void Lift::set_direction(int d) {
    liftMotor.Set(d);
}

float potToAngle(float p) {
    return p; // Todo add formula here
}
float angleToPot(float a) {
    return a; // Todo Add Formula Here
}
void Lift::update() {
    if(manual) {
        return;
    }
    float cur_angle = get_current_angle();
    if(at_angle()) {
        set_direction(0);
        manual = true;
        return;
    }
    if(cur_angle < target_angle) {
        set_direction(1);
    } 
    else
    {
        set_direction(-1);
    }
}
void Lift::updateHelper(UpdateRegistry::inst a) {
    ((Lift*)a) -> update();
}
