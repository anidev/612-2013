#ifndef PRESETS_H
#define PRESETS_H

#include "lift.h"
#include "AutoShooter.h"
#include "launcher.h"
#include "shooter.h"

class presets {  // two presets; speed of the wheel, angle of the launcher;
private:
    int wheel_speed;
    float lift_angle;
    bool isAtAngle;
    bool isAtSpeed;
    bool isFinished; // assumes that the preset(s) are not finished

public:
    presets(float, int);
	~presets();
    void set_lift_angle(float);
    void set_wheel_speed(int);
    float get_pre_lift();
    int get_pre_speed();
 // bool shootAgain();
    void check_presets(); // checks the bools of shooterAim/launcher/lift
    void pre_update();  // paired with prep_shoot to ensure it is ready to fire
    void prep_shoot();  // should be added to shooter inorder to check the feeder and lift if they are fininshed
    void pre_abort();  //not to be confused with abort in shooter.h
};
#endif
