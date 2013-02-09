//amusement
#ifndef AUTOSHOOTER_H
#define AUTOSHOOTER_H

#include <vector>
#include "vision/vision.h"
#include "shooter.h"
#include "realityEngine.h"

const float ANGLE_TOLERANCE = 3; //Deg
const float LIFT_TOLERANCE = 0.1; //Deg
class AutoShooter {
private:
    enum states {
        OFF,
        VISION,
        SETTING,
        WAITING,
        SHOOTING,
        DONE
    } cur_state;
    unsigned int targetShotCount;
    RealityData currentTarget;
    void setCurrentTarget();
    void doSetting();
    void doShooting();
    Shooter* shooter;
    bool isAimed();
    void update();
    static void update_helper(void*);
    static void toggle_helper(void*);
public:
    static const unsigned int MAX_FRISBEE_COUNT = 4;
    AutoShooter(Shooter*);
    ~AutoShooter();
    void AutoShoot(int target = MAX_FRISBEE_COUNT);
    void StopAutoShoot();
    bool doneShooting();
    void abort();
};
#endif
