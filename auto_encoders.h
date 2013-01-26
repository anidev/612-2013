#ifndef AUTO_ENCODERS
#define AUTO_ENCODERS

#include <Encoder.h>
#include "ports.h"

class auto_encoders {
private:
    bool is_driving;
    double distance;
    double left_distance;
    double right_distance;
    Encoder* left_encoder;
    Encoder* right_encoder;
    double get_avg_ticks();
    double convert_distance(double);
    static const double WHEEL_RADIUS = 4.0;
    //static const double WHEEL_CIRCUMFERENCE = WHEEL_RADIUS * 2 * pi;
    static const double TICKS_PER_REV = 250; // PULSES PER REV = 125, DISTANCE PER PULSE = circumference / 125
    static const double DRIVE_REDUCTION = 38.0/60;
    static const double SLOPE = 0.0677751556;
public:
    ~auto_encoders();
    auto_encoders(hw_info, hw_info, hw_info, hw_info);
    double get_target_distance();
    double get_distance();
    double get_left_dist();
    double get_right_dist();
    double get_left_target_dist();
    double get_right_target_dist();
    void start_left_driving(double);
    void start_right_driving(double);
    void reset_left_distance();
    void reset_right_distance();
    bool left_at_target();
    bool right_at_target();
    void reset_distance();
    void start_driving(double);
    void stop_driving();
};

#endif
