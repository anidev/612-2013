#include <cmath>
#include "EnhancedShooter.h"
#include "main.h"

EnhancedShooter::EnhancedShooter(int w,hw_info wc,int L,hw_info f,hw_info c,void* o): // wheel, wheel sensor, lift, feeder, feeder sensor
        wheel(w),
        lift(L),
        feeder(f.moduleNumber,f.channel),HalEffect(c.moduleNumber,c.channel) ,
        wheelCount(wc.moduleNumber,wc.channel),
        wheelCommandCenter(WHEEL_P,WHEEL_I,WHEEL_D,&wheelCount,&wheel)
{
    (((robot_class*)o) -> updateRegistry).addUpdateFunction(&update_helper,(void*)this);
    driver = &((robot_class*)o) -> drive_gamepad;
    gunner = &((robot_class*)o) -> gunner_gamepad;
    driver -> addBtn(GUNNER_BTN_LIFT_LOAD_PRESET,&loadPreset,(void*)this);
    robotState = &((robot_class*)o) -> curState;
    HalEffect.Start();
}
void EnhancedShooter::setWheelPower(float speed) {
    wheelCommandCenter.Disable();
    wheel.ChangeControlMode(CANJaguar::kPercentVbus);
    wheel.Set(speed);
}
void EnhancedShooter::setFeeder(direction dir) {
    feeder.Set(dir * FEEDER_SPEED);
}
void EnhancedShooter::setLiftPower(float pwr) {
    lift.ChangeControlMode(CANJaguar::kPercentVbus);
    lift.Set(pwr);
}
void EnhancedShooter::update() {
    if(*robotState == robot_class::NORMAL)
    {
        if(HalEffect.Get() > 0)
        {
            stopFeeder();
            HalEffect.Reset();
            HalEffect.Start();
        }
    }
    else
    {
        setLiftPower(-1 * LIFT_POWER); //Limit Switch Will Stop It
        stopFeeder();
        stopWheel();
    }
}
void EnhancedShooter::stopAll() {
    stopWheel();
    stopFeeder();
    stopLift();
}

void EnhancedShooter::stopWheel() {
    wheelCommandCenter.Disable();
    wheel.ChangeControlMode(CANJaguar::kVoltage);
    wheel.Set(0.0f); // Set to 0 before disabling because Set re-enables
    wheel.DisableControl();
}
void EnhancedShooter::stopLift() {
    lift.ChangeControlMode(CANJaguar::kVoltage);
    lift.Set(0.0f);
    lift.DisableControl();
}
void EnhancedShooter::stopFeeder() {
    feeder.Set(0.0f);
}
void EnhancedShooter::doControls() {
    if(*robotState != robot_class::NORMAL)
        return; // NO conrols in climbing mode
    //Wheel Control
    if(gunner -> GetRawButton(GUNNER_BTN_SHOOTER_WHEEL))
    {
        setSpeed(60.0);
    }
    else if(gunner -> GetRawButton(GUNNER_BTN_SHOOTER_WHEEL_REV))
    {
        setSpeed(-60.0);
    }
    else
    {
        stopWheel();
    }
    //Lift Control
    if(gunner -> GetRawButton(GUNNER_BTN_LIFT_UP))
    {
        setLiftPower(LIFT_POWER);
    }
    else if(gunner -> GetRawButton(GUNNER_BTN_LIFT_DOWN))
    {
        setLiftPower(-1 * LIFT_POWER);
    }
    else
    {
        stopLift();
    }
    //Feeder Controls
    if(gunner -> GetRawAxis(GUNNER_AXIS_FEEDER) < -0.98f) // right
    {
        setFeeder(FORWARD);
    }
    else if(gunner -> GetRawAxis(GUNNER_AXIS_FEEDER) > 0.98f) // left
    {
        setFeeder(BACKWARD);
    }
}
void EnhancedShooter::setAngle(float newTarget) {
    lift.EnableControl();
    lift.ChangeControlMode(CANJaguar::kPosition);
    lift.SetPositionReference(CANJaguar::kPosRef_Potentiometer);
    lift.SetPID(LIFT_P,LIFT_I,LIFT_D);
    newTarget = liftAngleToPot(newTarget);
    lift.Set(newTarget);
}
float EnhancedShooter::getCurrentAngle() {
    lift.SetPositionReference(CANJaguar::kPosRef_Potentiometer);
    return liftPotToAngle(lift.GetPosition());
}
float EnhancedShooter::getPot() {
    lift.SetPositionReference(CANJaguar::kPosRef_Potentiometer);
    return lift.GetPosition();
}
void EnhancedShooter::setSpeed(float newTarget) {
    wheelCommandCenter.Enable();
    wheelCommandCenter.SetOutputRange(-1.00,1.00);
    wheelCommandCenter.SetAbsoluteTolerance(WHEEL_TOLERANCE);
    wheelCommandCenter.SetSetpoint(newTarget);
}
bool EnhancedShooter::atAngle(float target) {
    target = liftAngleToPot(target);
    if(target <= MIN_POT_VAL)
        return lift.GetForwardLimitOK();
    else if(target >= MAX_POT_VAL)
        return lift.GetReverseLimitOK();
    if(std::fabs(lift.Get() - target) < LIFT_TOLERANCE)
        return true;
    return false;
}
bool EnhancedShooter::atSpeed(float target) {
//    if(std::fabs((1.0f/wheelCount.GetPeriod()) - target) < WHEEL_TOLERANCE)
    if(wheelCommandCenter.OnTarget()) // should work
        return true;
    return false;
}
float EnhancedShooter::liftAngleToPot(float angle) {
    //TODO insert Equation Here angle->pot
    return 0.5f;
}
float EnhancedShooter::liftPotToAngle(float pot) {
    // TODO insert Equation Here pot->angle
    return 0.0f;
}
void EnhancedShooter::update_helper(void* o) {
    ((EnhancedShooter*)o) -> update();
}
void EnhancedShooter::disable(void* o) {
    ((EnhancedShooter*)o) -> stopAll();
}
void EnhancedShooter::loadPreset(void* o) {
    ((EnhancedShooter*)o) -> setAngle(LIFT_LOAD_PRESET);
}
