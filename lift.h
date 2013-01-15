#ifndef LIFT_H_INCLUDED
#define LIFT_H_INCLUDED

class Lift {
private:
    static const float AT_ANGLE_TOLERANCE=0.5;
    bool manual;
    float target_angle;
    void set_direction(int);
    void automatic_update();

public:
    Lift();
    ~Lift();

    void lift_up();
    void lift_down();
    void lift_stop();
    void set_angle(float);
    float get_current_angle();
    float get_target_angle();
    bool at_angle();
};

#endif // LIFT_H_INCLUDED
