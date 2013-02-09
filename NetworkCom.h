#ifndef NETWORKCOM_H_INCLUDED
#define NETWORKCOM_H_INCLUDED

#include <networktables/NetworkTable.h>

class NetworkCom {
public:
    NetworkCom();
    ~NetworkCom();
    void target_available (bool);
    void target_x (double new_target);
    void target_y (double new_target);
    void target_width (double new_target);
    void target_height (double new_target);
    void launcher_target_speed (double new_speed);
    void launcher_current_speed (double cur_speed);
    void lift_angle (float new_angle);
private:
    NetworkTable* Main;
    NetworkTable* Tracking;
    NetworkTable* Gunner;
    NetworkTable* Autonomous;
};

#endif // NETWORKCOM_H_INCLUDED
