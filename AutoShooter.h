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
    void doAngleSetting();
    Shooter* shooter;
    bool isAimed();
    void update();
    static void update_helper(void*);
public:
    AutoShooter(Shooter*);
    ~AutoShooter();
    void AutoShoot();
    void StopAutoShoot();
    bool doneShooting();
};
#endif
/*        Assumes
 * 1. vision.h has target class
 * 2. shooter has aim_left() aim_right() aim_up() aim_down()
 * 3. vector<target> currentTargets is included in vision class as a protected variable
 * 4. vision class has ShooterAim as friend
 * 5. target has getPriority();
 */
