#ifndef AUTO_ENCODERS
#define AUTO_ENCODERS

#include <Encoder.h>
#include "ports.h"

struct encoders_info {
    hw_info left1;
    hw_info left2;
    hw_info right1;
    hw_info right2;
};

class auto_encoders {
private:
    Encoder* left_encoder;
    Encoder* right_encoder;
    static const double WHEEL_RADIUS = 4.0;
    //static const double WHEEL_CIRCUMFERENCE = WHEEL_RADIUS * 2 * pi;
    static const double TICKS_PER_REV = 250; // PULSES PER REV = 125, DISTANCE PER PULSE = circumference / 125
    static const double DRIVE_REDUCTION = 38.0/60;
    static const double SLOPE = 0.0677751556;
    static const double TOLERANCE = 1.5;
public:
    ~auto_encoders();
    auto_encoders(encoders_info);
    double get_distance();
    double get_left_dist();
    double get_right_dist();
    void reset_left_distance();
    void reset_right_distance();
    void reset_distance();
};

#endif
