#include <cmath>
#include <Jaguar.h>
#include <PIDController.h>
#include "ports.h"
#include "launcher.h"
#include "612.h"
#include "NetworkCom.h"

#ifdef Suzie
const float PID_P = 0.002f;
const float PID_I = 0.0f;
const float PID_D = 0.005f;
#else
const float PID_P = 0.3f;
const float PID_I = 0.005f;
const float PID_D = 0.0f;
#endif

#ifdef Suzie
Launcher::Launcher(hw_info wheel1,hw_info wheel2,hw_info sensor) : launcherWheel(wheel1,wheel2),
                                                                   launcherSensor(sensor.moduleNumber, sensor.channel),
                                                                   pid(PID_P, PID_I, PID_D, &launcherSensor, &launcherWheel)
{
#else
Launcher::Launcher(canport_t wheelInfo,hw_info sensorInfo) : launcherWheel(wheelInfo),
                                                             launcherSensor(sensorInfo.moduleNumber, sensorInfo.channel),
                                                             pid(PID_P, PID_I, PID_D, &launcherSensor, &launcherWheel) 
{
    launcherWheel.ChangeControlMode(CANJaguar::kPercentVbus);
#endif
    count = 0;
    targetSpeed = 0;
    targetSet = false;
    updateRegistry.addUpdateFunction(&update_helper,(void*)this);
    pid.Disable();
    pid.SetTolerance(AT_SPEED_TOLERANCE);
    pid.SetInputRange(0.0f, MAX);
    pid.SetOutputRange(-1.0f, 1.0f);
    launcherSensor.SetMaxPeriod(10);
    launcherSensor.Start();
}

Launcher::~Launcher() {
}

void Launcher::stop() {
    targetSet = false;
    reachedSpeed = false;
    targetSpeed = 0.0f;
    launcherWheel.Set(0.0f);
    pid.Disable();
}

void Launcher::setSpeed(float newSpeed) {
    targetSpeed = newSpeed;
    targetSet = true;
    reachedSpeed = false;
    launcherWheel.Set(0.4f);
    //launcherWheel.Set(newSpeed); //TODO undo if pid fails
    pid.Enable();
    pid.SetSetpoint(newSpeed);
}

float Launcher::getCurrentSpeed() {
    return 1.0f/(launcherSensor.GetPeriod());
}

float Launcher::getTargetSpeed() {
    return targetSpeed;
}

bool Launcher::atSpeed(){
    if((std::fabs(getCurrentSpeed() - targetSpeed)/targetSpeed) < AT_SPEED_TOLERANCE){
        return true;
    }
    return false; //Replaces OnTarget because it locks up
    //Todo test onTarget
}

void Launcher::resetFrisbeeCount(){
    count = 0;
}

unsigned int Launcher::getFrisbeeCount(){
    return count;
}
//extern ports.h

bool Launcher::dropDetected() {
    return (std::fabs(getCurrentSpeed() - targetSpeed) > SHOT_DROP_TOLERANCE);
}

void Launcher::update() {
    netcom -> launcher_current_speed(getCurrentSpeed()); //get current speed and send with netcom
    if(targetSet)
    {
        if(atSpeed())
        {
            reachedSpeed = true;
        }
        if(reachedSpeed)
        {
            if(dropDetected())
            {
                count++;
                reachedSpeed = false;
            }
        }
    }
}
void Launcher::update_helper(void* obj) {
    ((Launcher*)obj) -> update();
}
