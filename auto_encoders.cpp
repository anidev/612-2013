#include "612.h"
#include "auto_encoders.h"

auto_encoders::auto_encoders(hw_info left1, hw_info right1, hw_info left2, hw_info right2) {
    left_encoder = new Encoder(left1.moduleNumber, left1.channel, left2.moduleNumber, left2.channel, true);
    right_encoder = new Encoder(right1.moduleNumber, right1.channel, right2.moduleNumber, right2.channel);
    left_encoder->SetDistancePerPulse(SLOPE);
    right_encoder->SetDistancePerPulse(SLOPE);
    left_encoder->Start();
    right_encoder->Start();
}
auto_encoders::~auto_encoders() {
    left_encoder->Stop();
    right_encoder->Stop();
    delete left_encoder;
    delete right_encoder;
}
double auto_encoders::get_avg_ticks() {
    return (left_encoder->Get() + right_encoder->Get()) / 2;
}
double auto_encoders::convert_distance(double ticks) {
    //this finds distance in inches
    return (ticks/TICKS_PER_REV)*(WHEEL_RADIUS*(M_PI));
}
double auto_encoders::get_target_distance() {
    return distance;
}
double auto_encoders::get_distance() {
/*    double ticks=get_avg_ticks();
    return convert_distance(ticks);*/
    return (left_encoder->GetDistance()+right_encoder->GetDistance())/2.0;
//    std::printf("ticks avg: %f\n",get_avg_ticks());
//    return 0.0;
}
double auto_encoders::get_left_dist() {
    return left_encoder->GetDistance();
}
double auto_encoders::get_right_dist() {
    return right_encoder->GetDistance();
}
double auto_encoders::get_left_target_dist() {
    return left_distance; 
}
double auto_encoders::get_right_target_dist() {
    return right_distance;
}
void auto_encoders::start_left_driving(double dist) {
   left_distance = dist; 
}
void auto_encoders::start_right_driving(double dist) {
    right_distance = dist;
}
void reset_left_distance() {
    left_encoder->Reset();
}
void reset_right_distance() {
    right_encoder->Reset();
}
bool left_at_target() {
    return ((std::fabs(left_distance) - get_left_dist)) < 1.5);
}
bool right_at_target() {
    return ((std::fabs(right_distance) - get_right_dist)) < 1.5);
}
void auto_encoders::reset_distance(){
    left_encoder->Reset();
    right_encoder->Reset();
}
void auto_encoders::start_driving(double dist){
    is_driving = true;
    distance = dist;
}
void auto_encoders::stop_driving() {
    distance = 0;
    is_driving = false;
}
