#include "auto_encoders.h"

auto_encoders::auto_encoders(hw_info left1, hw_info right1, hw_info left2, hw_info right2) {
    left_encoder = new Encoder(left1.moduleNumber, left1.channel, left2.moduleNumber, left2.channel);
    right_encoder = new Encoder(right1.moduleNumber, right1.channel, right2.moduleNumber, right2.channel);
}
double auto_encoders::calc_distance() {
    return (left_encoder.Get() + right_encoder.Get()) / 2;
}
double auto_encoders::convert_distance(double ticks) {
    //this finds distance in feet
    return (ticks/TICKS_PER_REV)*(WHEEL_RADIUS*(pi))/12;
}
double auto_encoders::get_distance() {
    return distance;
}
void auto_encoders::reset_distance(){
    left_encoder.Reset();
    right_encoder.Reset();
}    
void auto_encoders::start_driving(double dist){
    is_driving = true;
    distance = dist;
}
void auto_encoders::stop_driving() {
    distance = 0;
    is_driving = false;
}
