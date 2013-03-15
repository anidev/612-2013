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
#include "controls.h"

const float LIFT_SPEED = 0.4f;
const float POWER_CHANGE_FOR_LOADED = 0.05; //%5 power change
const float LIFT_BOOST_POWER = LIFT_SPEED + POWER_CHANGE_FOR_LOADED;
const float LIFT_WEAKER_POWER = LIFT_SPEED - POWER_CHANGE_FOR_LOADED;

const float MAX_POT_UP = 5.19; //angle = 31.5
const float MAX_POT_DOWN = 5.498; //angle = -37.1
const float POT_ZERO = 5.327; //angle = 0

#ifdef Suzie
Lift::Lift(hw_info jagInfo,hw_info potInfo) : pot(potInfo.moduleNumber,potInfo.channel)
{
    liftMotor = new Jaguar(jagInfo.moduleNumber,jagInfo.channel);
#else
Lift::Lift(canport_t canJag)
{
    liftMotor = new CANJaguar(canJag);
    CANJaguar* liftCan = (CANJaguar*)liftMotor;
    liftCan -> SetSafetyEnabled(false);
    liftCan -> ChangeControlMode(CANJaguar::kPosition);
    liftCan -> SetPositionReference(CANJaguar::kPosRef_Potentiometer);
    liftCan -> ConfigPotentiometerTurns(POT_TURNS);
#endif // Suzie
    gunner_gamepad.addBtn(Gunner_Btn_LiftLoadPreset,&gunner_loaded_helper,(void*)this);
    updateRegistry.addUpdateFunction(&updateHelper,(void*)this);
    manual = true;
}
//Todo add command to set angle and have jag go to it(button)
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
    set_direction(0);
#ifndef Suzie
    ((CANJaguar*)liftMotor) -> ChangeControlMode(CANJaguar::kPosition);
    ((CANJaguar*)liftMotor) -> Set(new_angle);
#endif //Suzie
}

void Lift::set_pot(float new_pot) {
    manual = false;
#ifndef Suzie
    ((CANJaguar*)liftMotor) -> ChangeControlMode(CANJaguar::kPosition);
    ((CANJaguar*)liftMotor) -> Set(new_pot);
#endif //Suzie
}

void Lift::set_max_up() {
    set_pot(MAX_POT_UP);
}

void Lift::set_max_down() {
    set_pot(MAX_POT_DOWN);
}   



float Lift::getRawPotValue() { //Todo find a way to get raw pot value from canjag
#ifdef Suzie
    return pot.GetVoltage();
#else
    return ((CANJaguar*)liftMotor) -> GetPosition();
#endif //Suzie
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
#ifdef Suzie
    return ((-1.0207443959 * angle) + 4.1827946896);
#else
    return 0.0f; //Todo get Equation
#endif
}

float Lift::potToAngle(float voltage) {
#ifdef Suzie
    return ((-0.9129997242 * voltage) + 3.9002999384);
#else
    return 0.0f; //Todo get Equation
#endif
}

bool Lift::at_angle() {
    std::printf("pot angle diff: %f\n",get_current_angle()-target_angle);
    if (LM->getCurrent() == 0) {
        return true;
    } else {
        return false;
    }
    /*
    if(std::fabs(get_current_angle()-target_angle)<AT_ANGLE_TOLERANCE) {
        return true;
    }
    return false;*/
}

void Lift::set_direction(int d) {
    //TODO add when set to unloaded return to hal effect so its out of way of loading
#ifdef Suzie
    liftMotor -> Set(d*1.0f);
#else
    CANJaguar* LM = (CANJaguar*)liftMotor;
    LM -> DisableControl();
    LM -> ChangeControlMode(CANJaguar::kPercentVbus);
    if(potToAngle(LM -> GetPosition() > 0))
    {
        if(d > 0)
        {
            LM -> Set(d*LIFT_BOOST_POWER);
        }
        else
        {
            LM -> Set(d*LIFT_SPEED);
        }
    }
    else if(potToAngle(LM -> GetPosition() < 0))
    {
        if(d < 0)
        {
            LM -> Set(d*LIFT_BOOST_POWER);
        }
        else
        {
            LM -> Set(d*LIFT_SPEED);
        }
    }
    else
    {
        LM -> Set(d*LIFT_SPEED);
    }
#endif //Suzie
}

void Lift::update() {
    netcom->lift_angle(get_current_angle());
    if(manual) {
        return;
    }
    if(at_angle()) {
        set_direction(0);
        manual = true;
        return;
    }
#ifdef Suzie
    float cur_angle = get_current_angle();
    if(cur_angle < target_angle) {
        set_direction(1);
    }
    else
    {
        set_direction(-1);
    }
#endif // suzie
}
void Lift::updateHelper(void* a) {
    ((Lift*)a) -> update();
}
void Lift::gunner_loaded_helper(void* a)
{
    Lift* lift = (Lift*)a;
    lift -> loaded = !(lift ->loaded);
}
