#include <cmath>
#include "lift.h"
#include "ports.h"

Lift::Lift(hw_info info) : liftMotor(info.moduleNumber,info.channel)
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
    // TODO
    return 0.0f;
}

float Lift::get_target_angle() {
    return target_angle;
}

bool Lift::at_angle() {
    if(std::fabs(get_current_angle()-target_angle)<AT_ANGLE_TOLERANCE) {
        return true;
    }
    return false;
}

void Lift::set_direction(int d) {
    liftMotor.Set(d);
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
    if(cur_angle<target_angle) {
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
