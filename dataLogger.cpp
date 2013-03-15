#include <stdio.h>
#include <vision/HSLImage.h>
#include <vision/AxisCamera.h>
#include "dataLogger.h"
#include "ports.h"
#include "Shooter.h"
#include "612.h"
#include "lift.h"
#include "drivetrain.h"

static void AutoLogHelper(void* o) {
    ((DataLogger*)o) -> LogAutonomousSuccessPosition();
}

DataLogger::DataLogger(): systemTimer(),iterativeTimer() {
    iterativeTimer.Start();
    systemTimer.Start();
    updateRegistry.addUpdateFunction(&update_helper,(void*)this);
    drive_gamepad.addBtn(1,&AutoLogHelper,(void*)this);
}

void DataLogger::LogShot() {
    static unsigned int shotCount = 0;
    shotCount++;
    char buffer[500];
    sprintf(buffer,"Shot_%i_%f",shotCount,systemTimer.GetFPGATimestamp());
    File f(buffer);
    char buf2[30];
    sprintf(buf2,"Wheel Target: %f",shooter.getTargetSpeed());
    f.addLine(buf2);
    char buf3[30];
    sprintf(buf3,"Wheel Current: %f",shooter.getCurrentSpeed());
    f.addLine(buf2);
#ifndef Suzie
    char buf4[30];
    sprintf(buf4,"IR Raw: %f",shooter.IRSensor.GetVoltage());
    f.addLine(buf4);
    if(shooter.feed.counter.Get() > 0)
        f.addLine("Hal: 1");
    else
        f.addLine("Hal: 0");
#endif
    char ImageName[30];
    sprintf(ImageName,"ShotLogs/ShotLog%i_Launch",shotCount);
    LogCameraImage(ImageName);
    //todo Camera Image later
    //todo add angle
}

DataLogger::~DataLogger() {
    for(unsigned int i = 0; i < dValFiles.size(); i++)
    {
        delete dValFiles.at(i);
    }
    for(unsigned int i = 0; i < bValFiles.size(); i++)
    {
        delete bValFiles.at(i);
    }
    for(unsigned int i = 0; i < iValFiles.size(); i++)
    {
        delete iValFiles.at(i);
    }
    for(unsigned int i = 0; i < fValFiles.size(); i++)
    {
        delete fValFiles.at(i);
    }
}

void DataLogger::LogCameraImage(string s) {
    HSLImage* image = camera() -> GetImage();
    char tmp[100];
    sprintf(tmp,"%s_%f.jpeg",s.c_str(),systemTimer.GetFPGATimestamp());
    image -> Write(tmp);
    delete image;
}

void DataLogger::DumpDouble(double d,string name) {
    char buffer[200];
    sprintf(buffer,"loggedData/Double_%s_%f.txt",name.c_str(),systemTimer.GetFPGATimestamp());
    File f(buffer);
    char buf2[10];
    sprintf(buf2,"%f",d);
    f.addLine(buf2);
}

void DataLogger::DumpInt(int i,string name) {
    char buffer[200];
    sprintf(buffer,"loggedData/Int_%s_%f.txt",name.c_str(),systemTimer.GetFPGATimestamp());
    File f(buffer);
    char buf2[10];
    sprintf(buf2,"%i",i);
    f.addLine(buf2);
}

void DataLogger::DumpFloat(float val,string name) {
    char buffer[200];
    sprintf(buffer,"loggedData/Float_%s_%f.txt",name.c_str(),systemTimer.GetFPGATimestamp());
    File f(buffer);
    char buf2[10];
    sprintf(buf2,"%f",val);
    f.addLine(buf2);
}

void DataLogger::DumpBool(bool b,string name) {
    char buffer[200];
    sprintf(buffer,"loggedData/Bool_%s_%f.txt",name.c_str(),systemTimer.GetFPGATimestamp());
    File f(buffer);
    if(b)
        f.addLine("1");
    else
        f.addLine("0");
}


void DataLogger::TrackDouble(double* d,string name) {
    dVals.push_back(d);
    previousDVals.push_back(*d);
    double time = systemTimer.GetFPGATimestamp();
    char buffer[500];
    sprintf(buffer,"loggedData/%f_%s_Double.txt",time,name.c_str());
    File *f = new File(buffer);
    dValFiles.push_back(f);
    char buffer2[500];
    sprintf(buffer2,"Double Tracking for %s \nStart Time: %f",name.c_str(),time);
    dValFiles.at(dValFiles.size() - 1) -> addLine(buffer2);
}

void DataLogger::updateDoubleTracking() {
    for(unsigned int i = 0; i < dVals.size(); i++)
    {
        previousDVals.at(i) = *dVals.at(i);
        char buffer[10];
        sprintf(buffer,"%f",*dVals.at(i));
        dValFiles.at(i) -> addLine(buffer);
    }
}

void DataLogger::StopTrackingDouble(double* target) {
    for(unsigned int i = 0; i < dVals.size(); i++)
    {
        if(dVals.at(i) == target)
        {
            dVals.erase(dVals.begin() + i);
            previousDVals.erase(previousDVals.begin() + i);
            char buffer[500];
            sprintf(buffer,"End Time: %f",systemTimer.GetFPGATimestamp());
            dValFiles.at(i) -> addLine(buffer);
            dValFiles.erase(dValFiles.begin() + i);
        }
    }
}
void DataLogger::TrackFloat(float* val,string name) {
    fVals.push_back(val);
    previousFVals.push_back(*val);
    double time = systemTimer.GetFPGATimestamp();
    char buffer[500];
    sprintf(buffer,"loggedData/%f_%s_Float.txt",time,name.c_str());
    File *f = new File(buffer);
    fValFiles.push_back(f);
    char buffer2[500];
    sprintf(buffer2,"Float Tracking for %s \n Start Time: %f",name.c_str(),time);
    fValFiles.at(fValFiles.size() - 1) -> addLine(buffer2);
}

void DataLogger::updateFloatTracking() {
    for(unsigned int i = 0; i < fVals.size(); i++)
    {
        previousFVals.at(i) = *fVals.at(i);
        char buffer[500];
        sprintf(buffer,"%f",*fVals.at(i));
        fValFiles.at(i) -> addLine(buffer);
    }
}

void DataLogger::StopTrackingFloat(float* target) {
    for(unsigned int i = 0; i < fVals.size(); i++)
    {
        if(fVals.at(i) == target)
        {
            fVals.erase(fVals.begin() + i);
            previousFVals.erase(previousFVals.begin() + i);
            char buffer[500];
            sprintf(buffer,"End Time: %f",systemTimer.GetFPGATimestamp());
            fValFiles.at(i) -> addLine(buffer);
            fValFiles.erase(fValFiles.begin() + i);
        }
    }
}

void DataLogger::TrackInt(int* i,string name) {
    iVals.push_back(i);
    previousIVals.push_back(*i);
    double time = systemTimer.GetFPGATimestamp();
    char buffer[500];
    sprintf(buffer,"loggedData/%f_%s_Int.txt",time,name.c_str());
    File *f = new File(buffer);
    iValFiles.push_back(f);
    char buffer2[500];
    sprintf(buffer2,"Int Tracking for %s \n Start Time: %f",name.c_str(),time);
    iValFiles.at(iValFiles.size() - 1) -> addLine(buffer2);
}

void DataLogger::updateIntTracking() {
    for(unsigned int i = 0; i < iVals.size(); i++)
    {
        previousIVals.at(i) = *iVals.at(i);
        char buffer[500];
        sprintf(buffer,"%i",*iVals.at(i));
        iValFiles.at(i) -> addLine(buffer);
    }
}

void DataLogger::StopTrackingInt(int* target) {
    for(unsigned int i = 0; i < dVals.size(); i++)
    {
        if(iVals.at(i) == target)
        {
            iVals.erase(iVals.begin() + i);
            previousIVals.erase(previousIVals.begin() + i);
            char buffer[500];
            sprintf(buffer,"End Time: %f",systemTimer.GetFPGATimestamp());
            iValFiles.at(i) -> addLine(buffer);
            iValFiles.erase(iValFiles.begin() + i);
        }
    }
}


void DataLogger::TrackBool(bool* b,string name) {
    bVals.push_back(b);
    previousBVals.push_back(*b);
    double time = systemTimer.GetFPGATimestamp();
    char buffer[500];
    sprintf(buffer,"loggedData/%f_%s_Bool.txt",time,name.c_str());
    File *f = new File(buffer);
    bValFiles.push_back(f);
    char buffer2[500];
    sprintf(buffer2,"Bool Tracking for %s \n Start Time: %f",name.c_str(),time);
    bValFiles.at(bValFiles.size() - 1) -> addLine(buffer2);
}

void DataLogger::updateBoolTracking() {
    for(unsigned int i = 0; i < bVals.size(); i++)
    {
        previousBVals.at(i) = *bVals.at(i);
        if(*bVals.at(i))
            bValFiles.at(i) -> addLine("1");
        else
            bValFiles.at(i) -> addLine("0");
    }
}

void DataLogger::StopTrackingBool(bool* target) {
    for(unsigned int i = 0; i < bVals.size(); i++)
    {
        if(bVals.at(i) == target)
        {
            bVals.erase(bVals.begin() + i);
            previousBVals.erase(previousBVals.begin() + i);
            char buffer[500];
            sprintf(buffer,"End Time: %f",systemTimer.GetFPGATimestamp());
            bValFiles.at(i) -> addLine(buffer);
            bValFiles.erase(bValFiles.begin() + i);
        }
    }
}

void DataLogger::TrackMotorOutput(SpeedController* motor,string name) {
    mVals.push_back(motor);
    previousMVals.push_back(motor -> Get());
    double time = systemTimer.GetFPGATimestamp();
    char buffer[500];
    sprintf(buffer,"loggedData/%f_%s_Motor.txt",time,name.c_str());
    File *f = new File(buffer);
    mValFiles.push_back(f);
    char buffer2[500];
    sprintf(buffer2,"Motor Tracking for %s \n Start Time: %f",name.c_str(),time);
    mValFiles.at(mValFiles.size() - 1) -> addLine(buffer2);
}

void DataLogger::StopTrackingMotorOutput(SpeedController* target) {
    for(unsigned int i = 0; i < mVals.size(); i++)
    {
        if(mVals.at(i) == target)
        {
            mVals.erase(mVals.begin() + i);
            previousMVals.erase(previousMVals.begin() + i);
            char buffer[500];
            sprintf(buffer,"End Time: %f",systemTimer.GetFPGATimestamp());
            mValFiles.at(i) -> addLine(buffer);
            mValFiles.erase(mValFiles.begin() + i);
        }
    }
}

void DataLogger::updateMotorOutputTracking() {
    for(unsigned int i = 0; i < mVals.size(); i++)
    {
        previousMVals.at(i) = mVals.at(i) -> Get();
        char buffer[10];
        sprintf(buffer,"%f",mVals.at(i) -> Get());
        mValFiles.at(i) -> addLine(buffer);
    }
}

void DataLogger::update() {
    if(iterativeTimer.Get() >= UPDATE_RATE_TIME)
    {
        updateDoubleTracking();
        updateIntTracking();
        updateBoolTracking();
        updateMotorOutputTracking();
        iterativeTimer.Reset();
    }
}

void DataLogger::update_helper(void* o) {
    ((DataLogger*)o) -> update();
}

void DataLogger::LogLiftAngle() {
    double time = systemTimer.GetFPGATimestamp();
    char name[50];
    sprintf(name,"LiftAngle_%f.txt",time);
    File f(name);
    f.addLine("Lift Angle Standard Log");
    char buf[20];
    sprintf(buf,"Time: %f",time);
    char result[100];
    sprintf(result,"Raw: %f\nAngle: %f",angleAdjuster.getRawPotValue(),angleAdjuster.get_current_angle());
    f.addLine(buf);
    f.close();
}

void DataLogger::LogRPSofLauncher() {
    double time = systemTimer.GetFPGATimestamp();
    char name[50];
    sprintf(name,"Launcher_RPS_%f.txt",time);
    File f(name);
    char Header[100];
    sprintf(Header,"Launcher Log \n Start Time: %f",time);
    f.addLine(Header);
    char val[20];
    sprintf(val,"%f",shooter.getCurrentSpeed());
}

void DataLogger::saveNote(string text,string fileName) {
    char x[200];
    sprintf(x,"%s",fileName.c_str());
    File f(x);
    f.addLine(text);
}
void DataLogger::LogAutonomousSuccessPosition() {
    static unsigned int count = 0;
    count++;
    char buffer[500];
    sprintf(buffer,"AutonomousPos_%i_%i.txt",count,(int)systemTimer.GetFPGATimestamp());
    File f(buffer);
    char buf2[30];
    sprintf(buf2,"Wheel Target: %f",shooter.getTargetSpeed());
    f.addLine(buf2);
    char buf3[30];
    sprintf(buf3,"Wheel Current: %f",shooter.getCurrentSpeed());
    f.addLine(buf3);
#ifndef Suzie
    char buf4[30];
    sprintf(buf4,"IR Raw: %f",shooter.IRSensor.GetVoltage());
    f.addLine(buf4);
    if(shooter.feed.counter.Get() > 0)
        f.addLine("Hal: 1");
    else
        f.addLine("Hal: 0");
#endif
    char ImageName[30];
    sprintf(ImageName,"AutoPosLog%i",count);
    LogCameraImage(ImageName);
    double LR = drive_train.encoders.get_raw_left();
    double RR = drive_train.encoders.get_raw_right();
    double LD = drive_train.encoders.get_left_dist();
    double RD = drive_train.encoders.get_right_dist();
    char LocData[600];
    sprintf(LocData,"Encoder Left Raw: %f \nEncoder Right Raw: %f \nEncoder Left: %f \nEncoder Right: %f",LR,RR,LD,RD);
    f.addLine(LocData);
}
void DataLogger::SensorDataDump() {
    /*    Sensors
     * 1) Encoderss
     * 2) Pot
     * 3) Hal Effect
     * 4) IR
     * 5) Camera
     * 6) Launcher Hal Effect Speed
     */
    //todo Finish
    double time = systemTimer.GetFPGATimestamp();
    char name[30];
    sprintf(name,"SensorDump_%f.txt",time);
    File file(name);
}
