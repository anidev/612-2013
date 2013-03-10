#include <cmath>
#include "612.h"
#include "auto_encoders.h"

auto_encoders::auto_encoders(encoders_info info) {
    hw_info left1 = info.left1;
    hw_info left2 = info.left2;
    hw_info right1 = info.right1;
    hw_info right2 = info.right2;
    left_encoder = new Encoder(left1.moduleNumber, left1.channel, left2.moduleNumber, left2.channel, true);
    right_encoder = new Encoder(right1.moduleNumber, right1.channel, right2.moduleNumber, right2.channel);
#ifdef Suzie
    left_encoder -> SetDistancePerPulse(SLOPE);
    right_encoder -> SetDistancePerPulse(SLOPE);
#else
    left_encoder -> SetDistancePerPulse(SLOPE_LEFT);
    right_encoder -> SetDistancePerPulse(SLOPE_RIGHT);
#endif
    left_encoder -> Start();
    right_encoder -> Start();
}
auto_encoders::~auto_encoders() {
    left_encoder -> Stop();
    right_encoder -> Stop();
    delete left_encoder;
    delete right_encoder;
}
double auto_encoders::get_distance() {
    return (get_left_dist() + get_right_dist()) / 2.0;
}
double auto_encoders::get_left_dist() {
    static int counter=0;
    if(counter%25==0) {
//        std::printf("left dist:  %f\n",left_encoder->GetDistance());
    }
    counter++;
    return left_encoder -> GetDistance();
}
double auto_encoders::get_right_dist() {
    static int counter = 0;
    if(counter%25==0) {
//        std::printf("right dist: %f\n",right_encoder->GetDistance());
    }
    counter++;
    return right_encoder -> GetDistance();
}
void auto_encoders::reset_left_distance() {
    left_encoder -> Reset();
}
void auto_encoders::reset_right_distance() {
    right_encoder -> Reset();
}
void auto_encoders::reset_distance(){
    left_encoder -> Reset();
    right_encoder -> Reset();
}
