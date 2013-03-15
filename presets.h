#ifndef PRESETS_H
#define PRESETS_H

#include "lift.h"
#include "shooter.h"

class presets {  // two presets; speed of the wheel, angle of the launcher;
private:
    unsigned int wheel_speed;
    float lift_angle;
    /*
     * int lift_angle_high = over 9000
     * int lift_angle_med  = 42
     * int turn_angle_mid  = 360
     * int turn_angle_lr   = 0;
     * NOTE THESE PRESETS HAVEN'T BEEN SET YET. IF THEY ARE IN ANOTHER CLASS, NOTIFY ME SO THAT I MAY FIX THIS.
     */
public:
    presets(float,unsigned int);
	~presets();
    void setShooter(Shooter*);
    void setLifter(Lift*);
};
#endif
