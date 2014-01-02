#include <cstdio>
#include <Timer.h>
#include "dataLogger.h"
#include "EnhancedShooter.h"
#include "EnhancedJoystick.h"
#include "Controls.h"

DataLogger::DataLogger(EnhancedShooter* s,void* o):shooter(s) {
    gunner = &((robot_class*)o) -> gunner_gamepad;
    gunner -> addBtn(GUNNER_BTN_SUCCESS_LOG,&successLog,(void*)this);
}

void DataLogger::successLog(void* o) {
    EnhancedShooter* shooter = ((DataLogger*)o) -> shooter;
//    float angle=shooter->getCurrentAngle();
    float pot=shooter->getPot();
    double timestamp=Timer::GetFPGATimestamp();
    char filename[128];
    snprintf(filename,128,"%f_SuccessfulShot.log",timestamp);
    FILE* file=fopen(filename,"w");
//    fprintf(file,"Angle = %f\n",angle);
    fprintf(file,"Pot = %f\n",pot);
    fflush(file);
    fclose(file);
}
