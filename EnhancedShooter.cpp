#include <cmath>
#include "EnhancedShooter.h"
#include "main.h"

EnhancedShooter::EnhancedShooter(int w,hw_info wc,int L,hw_info f,hw_info c,void* o): // wheel, wheel sensor, lift, feeder, feeder sensor
        wheel(w),
        lift(L),
        feeder(f.moduleNumber,f.channel),HalEffect(c.moduleNumber,c.channel) ,
        wheelCount(wc.moduleNumber,wc.channel),
        wheelCommandCenter(WHEEL_P,WHEEL_I,WHEEL_D,&wheelCount,&wheel),
        wheelForward(false)
{
    lift.ChangeControlMode(CANJaguar::kPercentVbus);
    lift.SetPositionReference(CANJaguar::kPosRef_Potentiometer);
    wheel.ChangeControlMode(CANJaguar::kPercentVbus);
    wheelCommandCenter.SetPID(WHEEL_P,WHEEL_I,WHEEL_D);
    (((robot_class*)o) -> updateRegistry).addUpdateFunction(&update_helper,(void*)this);
    driver = &((robot_class*)o) -> drive_gamepad;
    gunner = &((robot_class*)o) -> gunner_gamepad;
    gunner -> addBtn(GUNNER_BTN_SHOOTER_WHEEL,&wheelToggle,(void*)this);
    gunner -> addBtn(GUNNER_BTN_PRESET_FRONT,&presetFront,(void*)this);
    gunner -> addBtn(GUNNER_BTN_PRESET_BACK,&presetBack,(void*)this);
    gunner -> addBtn(GUNNER_BTN_LIFT_LOAD_PRESET,&loadPreset,(void*)this);
    robotState = &(((robot_class*)o) -> curState);
    wheelCount.Start();
    HalEffect.Start();
    liftTargetSet = false;
    liftTarget = liftAngleToPot(0.0f);
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
    liftTargetSet = false;
    lift.ChangeControlMode(CANJaguar::kPercentVbus);
    lift.Set(pwr);
}
void EnhancedShooter::update() {
    if(*robotState == robot_class::NORMAL)
    {
        if(liftTargetSet)
        {
            if(atPot(liftTarget))
            {
                liftTargetSet = false;
                stopLift();
            }
            else if(lift.GetPosition() < liftTarget)
            {
                lift.Set(0.3141592654);
            }
            else
            {
                lift.Set(-1.0f * 0.3141592654);
            }
        }
        if(HalEffect.Get() > 0)
        {
            stopFeeder();
            HalEffect.Reset();
            HalEffect.Start();
        }
        if(gunner -> GetRawButton(GUNNER_BTN_SHOOTER_WHEEL_REV)) {
            wheelForward = false;
            setSpeed(-1.0f * WHEEL_POWER);
        }
        else if(wheelForward)
        {
            setSpeed(WHEEL_POWER);
        }
        else
        {
            stopWheel();
        }
    }
    else
    {
        setLiftPower(-1.0f * LIFT_POWER); //Limit Switch Will Stop It
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
    wheel.ChangeControlMode(CANJaguar::kPercentVbus);
    wheel.Set(0.0f); // Set to 0 before disabling because Set re-enables
    wheel.DisableControl();
}
void EnhancedShooter::stopLift() {
    lift.ChangeControlMode(CANJaguar::kPercentVbus);
    lift.Set(0.0f);
    lift.DisableControl();
}
void EnhancedShooter::stopFeeder() {
    feeder.Set(0.0f);
}
void EnhancedShooter::doControls() {
    if(*robotState != robot_class::NORMAL)
        return; // NO conrols in climbing mode
    //Lift Control
    if(gunner -> GetRawButton(GUNNER_BTN_LIFT_UP))
    {
        setLiftPower(LIFT_POWER);
    }
    else if(gunner -> GetRawButton(GUNNER_BTN_LIFT_DOWN))
    {
        setLiftPower(-1.0f * LIFT_POWER);
    }
    else if(!liftTargetSet)
    {
        stopLift();
    }
    //Feeder Controls
    if(gunner -> GetRawAxis(GUNNER_AXIS_FEEDER) > 0.98f) // right
    {
        setFeeder(FORWARD);
    }
    else if(gunner -> GetRawAxis(GUNNER_AXIS_FEEDER) < -0.98f) // left
    {
        setFeeder(BACKWARD);
    }
}
void EnhancedShooter::setAngle(float newTarget) {
    liftTarget = liftAngleToPot(newTarget);
    liftTargetSet = true;
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
    return atPot(target);
}
bool EnhancedShooter::atPot(float target) {
    if(target <= MIN_POT_VAL)
        return lift.GetForwardLimitOK();
    else if(target >= MAX_POT_VAL)
        return lift.GetReverseLimitOK();
    if(std::fabs(lift.GetPosition() - target) < LIFT_TOLERANCE)
        return true;
    return false;
}
bool EnhancedShooter::atSpeed(float target) {
    static int counter=0;
    if(counter%20==0) {
        printf("wheel speed = %f\n",1.0f/wheelCount.GetPeriod());
    }
    counter++;
    if((1.0f/wheelCount.GetPeriod()) > target)
        return true;
    return false;
}
float EnhancedShooter::liftAngleToPot(float angle) {
    return ((0.0035 * angle) + 0.3763);
}
void EnhancedShooter::update_helper(void* o) {
    ((EnhancedShooter*)o) -> update();
}
void EnhancedShooter::disable(void* o) {
    ((EnhancedShooter*)o) -> stopAll();
}
void EnhancedShooter::wheelToggle(void* o) {
    std::printf("wheel toggle\n");
    bool wheelForward = ((EnhancedShooter*)o) -> wheelForward;
    ((EnhancedShooter*)o) -> wheelForward = !wheelForward;
}
void EnhancedShooter::presetFront(void* o) {
    ((EnhancedShooter*)o) -> setAngle(LIFT_PRESET_FRONT);
}
void EnhancedShooter::presetBack(void* o) {
    ((EnhancedShooter*)o) -> setAngle(LIFT_PRESET_BACK);
}
void EnhancedShooter::loadPreset(void* o) {
    ((EnhancedShooter*)o) -> setAngle(LIFT_LOAD_PRESET);
}
float EnhancedShooter::liftPotToAngle(float a) {
    return 3.141592654f;
}
