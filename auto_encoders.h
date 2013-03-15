#ifndef AUTO_ENCODERS
#define AUTO_ENCODERS

#include <Encoder.h>
#include "ports.h"
#include "612.h"
#include "dataLogger.h"

struct encoders_info {
    hw_info left1;
    hw_info left2;
    hw_info right1;
    hw_info right2;
};

class auto_encoders {
friend class DataLogger;
protected:
    double get_raw_left();
    double get_raw_right();
private:
    Encoder* left_encoder;
    Encoder* right_encoder;
#ifdef Suzie
    static const double SLOPE = 0.0677751556; //inches per pulse
#else
    static const double SLOPE_LEFT =  0.0495;
    static const double SLOPE_RIGHT = 0.03495;
#endif //Suzie
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
