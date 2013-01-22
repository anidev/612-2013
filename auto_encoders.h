#ifndef AUTO_ENCODERS
#define AUTO_ENCODERS

#include <Encoder.h>
#include "ports.h"

class auto_encoders {
private:
    double distance;
    Encoder* left_encoder;
    Encoder* right_encoder;
    double get_avg_ticks();
    double convert_distance(double);
    static const double WHEEL_RADIUS = 8.0/2;
    static const double TICKS_PER_REV = 250;
    static const double DRIVE_REDUCTION = 38.0/60;
    static const double pi = 3.14159265358979;
public:
    ~auto_encoders();
    auto_encoders(hw_info, hw_info, hw_info, hw_info);
    double get_target_distance();
    double get_distance();
    void reset_distance();
    void start_driving(double);
    void stop_driving();
};

#endif
