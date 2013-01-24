#include "612.h"
#include "auto_encoders.h"

auto_encoders::auto_encoders(hw_info left1, hw_info right1, hw_info left2, hw_info right2) {
    left_encoder = new Encoder(left1.moduleNumber, left1.channel, left2.moduleNumber, left2.channel, true);
    right_encoder = new Encoder(right1.moduleNumber, right1.channel, right2.moduleNumber, right2.channel);
    left_encoder->SetDistancePerPulse(0.0573026500014);
    right_encoder->SetDistancePerPulse(0.0573026500014);
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
}
void auto_encoders::reset_distance(){
    left_encoder->Reset();
    right_encoder->Reset();
}
/*
void auto_encoders::start_driving(double dist){
    is_driving = true;
    distance = dist;
}
*/
void auto_encoders::stop_driving() {
    distance = 0;
    is_driving = false;
}
