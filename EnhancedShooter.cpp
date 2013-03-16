#include "EnhancedShooter.h"
#include "main.h"
EnhancedShooter::EnhancedShooter(int w,int L,robot_class::hw_info f,robot_class::hw_info c,void* o):wheel(w),lift(L),feeder(f.moduleNumber,f.channel),HalEffect(c.moduleNumber,c.channel) {
    (((robot_class*)o) -> updateRegistry).addUpdateFunction(&update_helper,(void*)this);
    driver = &((robot_class*)o) -> drive_gamepad;
    gunner = &((robot_class*)o) -> gunner_gamepad;
}
void EnhancedShooter::setWheelPower(float speed) {
    wheel.ChangeControlMode(CANJaguar::kVoltage);
    wheel.Set(speed);
}
void EnhancedShooter::setFeeder(direction_t dir) {
    feeder.Set(dir);
}
void EnhancedShooter::setLiftPower(float pwr) {
    lift.ChangeControlMode(CANJaguar::kVoltage);
    lift.Set(pwr);
}
void EnhancedShooter::update() {
    if(HalEffect.Get() > 0)
    {
        stopFeeder();
        HalEffect.Reset();
        HalEffect.Start();
    }
}
void EnhancedShooter::stopAll() {
    stopWheel();
    stopFeeder();
    stopLift();
}

void EnhancedShooter::stopWheel() {
    wheel.DisableControl();
    wheel.ChangeControlMode(CANJaguar::kVoltage);
    wheel.Set(0.0f);
}
void EnhancedShooter::stopLift() {
    lift.ChangeControlMode(CANJaguar::kVoltage);
    lift.Set(0.0f);
}
void EnhancedShooter::stopFeeder() {
    feeder.Set(0.0f);
}
void EnhancedShooter::doControls() {
    if(gunner -> GetRawButton(1))
    {
        setWheelPower(1.0);
    }
    else
    {
        setWheelPower(0.0);
    }
}
void EnhancedShooter::update_helper(void* o) {
    ((EnhancedShooter*)o) -> update();
}
void EnhancedShooter::disable(void* o) {
    ((EnhancedShooter*)o) -> stopAll();
}
