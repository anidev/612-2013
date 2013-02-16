#include <cmath>
#include <Jaguar.h>
#include <PIDController.h>
#include "ports.h"
#include "launcher.h"
#include "612.h"
#include "NetworkCom.h"

Launcher::Launcher(hw_info wheel1,hw_info wheel2,hw_info sensor) : launcherWheel(wheel1,wheel2),
                                                                   launcherSensor(sensor.moduleNumber, sensor.channel),
                                                                   pid(PID_P, PID_I, PID_D, &launcherSensor, &launcherWheel) {
    count = 0;
    targetSpeed = 0;
    targetSet = false;
    updateRegistry.addUpdateFunction(&update_helper,(void*)this);
    launcherSensor.Start();
    pid.Disable();
    pid.SetTolerance(AT_SPEED_TOLERANCE);
    pid.SetInputRange(0.0f, 65.0f);
    pid.SetOutputRange(-0.4f, 0.4f);
}

Launcher::~Launcher() {
}

void Launcher::stop() {
    targetSet = false;
    pid.Disable();
    targetSpeed=0.0f;
    launcherWheel.Set(0.0f);
    //insert more code here
}

void Launcher::setSpeed(float newSpeed) {
    targetSpeed=newSpeed;
    targetSet=true;
    launcherWheel.Set(0.3);
    pid.Enable();
    pid.SetSetpoint(newSpeed);
}

float Launcher::getCurrentSpeed() {
    std::printf("getting current speed when period=%f\n",launcherSensor.GetPeriod());
    return 1.0f/(launcherSensor.GetPeriod());
}

float Launcher::getTargetSpeed() {
    return targetSpeed;
}

bool Launcher::atSpeed(){
    if(std::fabs(getCurrentSpeed()-targetSpeed)/targetSpeed < AT_SPEED_TOLERANCE){
        return true;
    }
    return false; //Replaces OnTarget because it crashes
}

void Launcher::resetFrisbeeCount(){
    count = 0;
}

unsigned int Launcher::getFrisbeeCount(){
    return count;
}
//extern ports.h
void Launcher::update() {
	netcom.launcher_current_speed(getCurrentSpeed());
}
//get current speed and angle and send with netcom
void Launcher::update_helper(void* obj) {
    Launcher* launcher=(Launcher*)obj;
    launcher->update();
}
