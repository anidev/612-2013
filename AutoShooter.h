//amusement
#ifndef AUTOSHOOTER_H
#define AUTOSHOOTER_H

#include <vector>
#include "vision/vision.h"
#include "shooter.h"

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
    void AutoShoot(int);
    void StopAutoShoot();
    bool doneShooting();
    void abort();
};
#endif
/*        Assumes
 * 1. vision.h has target class
 * 2. shooter has aim_left() aim_right() aim_up() aim_down()
 * 3. vector<target> currentTargets is included in vision class as a protected variable
 * 4. vision class has ShooterAim as friend
 * 5. target has getPriority();
 */

