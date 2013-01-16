#ifndef SHIFTER_H
#define SHIFTER_H

#include "ports.h"

enum gear_t {
    LOW_GEAR,HIGH_GEAR;
};

class Shifter {
private:
    gear_t cur_gear;

public:
    Shifter(hw_info,hw_info);
    ~Shifter();

    gear_t get_gear();
    void set_gear(gear_t);
};

#endif //SHIFTER_H
