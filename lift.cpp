#include <SpeedController.h>
#include <Jaguar.h>
#include <CANJaguar.h>
#include <cmath>
#include <AnalogChannel.h>
#include "updateRegistry.h"
#include "ports.h"
#include "612.h"
#include "lift.h"
#include "NetworkCom.h"

#ifdef Suzie
Lift::Lift(hw_info jagInfo,hw_info potInfo) : pot(potInfo.moduleNumber,potInfo.channel)
{
    liftMotor = new Jaguar(jagInfo.moduleNumber,jagInfo.channel);
    updateRegistry.addUpdateFunction(&updateHelper,(void*)this);
    manual = true;
}
#else
Lift::Lift(canport_t canJag)
{
    liftMotor = new CANJaguar(canJag);
    CANJaguar* liftCan = (CANJaguar*)liftMotor;
    liftCan -> SetSafetyEnabled(false);
    liftCan -> ChangeControlMode(CANJaguar::kPosition);
    liftCan -> SetPositionReference(CANJaguar::kPosRef_Potentiometer);
    liftCan -> ConfigPotentiometerTurns(POT_TURNS);
    //liftCan -> ConfigSoftPositionLimits(LOWER_LIMIT,HIGHER_LIMIT); //Todo Set values then add
    updateRegistry.addUpdateFunction(&updateHelper,(void*)this);
    manual = true;
}    
#endif //Suzie
//Todo add command to set angle and have jag go to it
Lift::~Lift() {
    delete liftMotor;
}

void Lift::lift_up() {
    manual = true;
    set_direction(1);
}

void Lift::lift_down() {
    manual = true;
    set_direction(-1);
}

void Lift::lift_stop() {
    manual = true;
    set_direction(0);
}

void Lift::set_angle(float new_angle) {
    manual = false;
    target_angle = new_angle;
}

float Lift::get_current_angle() {
#ifdef Suzie
    return potToAngle(pot.GetVoltage());
#else
    return ((CANJaguar*)liftMotor) -> GetPosition();
#endif //Suzie
}

float Lift::get_target_angle() {
    return target_angle;
}

float Lift::angleToPot(float angle) {
    return ((-1.0207443959 * angle) + 4.1827946896); //Todo Check if this equation works
}

float Lift::potToAngle(float voltage) {
    return ((-0.9129997242 * voltage) + 3.9002999384); //Todo Check if this equation works
}

bool Lift::at_angle() {
    if(std::fabs(get_current_angle()-target_angle)<AT_ANGLE_TOLERANCE) {
        return true;
    }
    return false;
}

void Lift::set_direction(int d) {
    liftMotor -> Set(d*1.0f);
}

void Lift::update() {
    netcom.lift_angle(get_current_angle());
    if(manual) {
        return;
    }
    if(at_angle()) {
        set_direction(0);
        manual = true;
        return;
    }
    float cur_angle = get_current_angle();
    if(cur_angle < target_angle) {
        set_direction(1);
    }
    else
    {
        set_direction(-1);
    }
}
void Lift::updateHelper(void* a) {
    ((Lift*)a) -> update();
}
//Todo Implement these with Canbus
