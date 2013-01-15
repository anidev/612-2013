#include "ports.h"
#include "shifter.h"

Shifter::Shifter(hw_info left,hw_info right) {
    set_gear(LOW_GEAR);
}

Shifter::~Shifter() {
    //todo
}

gear_t Shifter::get_gear() {
    return cur_gear;
}

void Shifter::set_gear(gear_t new_gear) {
    cur_gear = new_gear;
}
