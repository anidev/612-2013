#ifndef AUTO_ENCODERS
#define AUTO_ENCODERS

#include <Encoder.h>

class auto_encoders {
private:
    double distance;
    Encoder* left_encoder;
    Encoder* right_encoder;
    double calc_distance();
    double convert_distance();
    const double WHEEL_RADIUS = 8.0/2;
    const double TICKS_PER_REV = 250;
    const double DRIVE_REDUCTION = 38.0/60;
    const double pi = 3.14159265358979;
public:
    auto_encoders(hw_info, hw_info, hw_info, hw_info);
    double get_distance();
    void reset_distance();
    void start_driving(double);
    void stop_driving();
};

#endif