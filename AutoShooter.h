//amusement
#ifndef AUTOSHOOTER_H
#define AUTOSHOOTER_H

#include <vector>
#include "vision/vision.h"
#include "shooter.h"
#include "realityEngine.h"

class AutoShooter {
private:
    enum states {
        OFF,
        VISION,
        HORIZONTAL,
        ANGLE_SETTING,
        SHOOTING,
        DONE
    } cur_state;
    unsigned int targetShotCount;
    void doVision();
    void doHorizontalAlign();
    void doAngleSetting();
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
