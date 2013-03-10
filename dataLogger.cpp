#include <stdio.h>
#include "dataLogger.h"
#include "ports.h"
#include "Shooter.h"
#include "612.h"
DataLogger::DataLogger(): systemTimer(),iterativeTimer() {
}

void DataLogger::LogShot() {
    static unsigned int shotCount = 0;
    shotCount++;
    char buffer[500];
    sprintf(buffer,"Shot_%i_%f",shotCount,systemTimer.Get());
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
    //todo Camera Image 2 sec later(refine as needed)
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
    ColorImage* image = camera()->GetImage();
    char tmp[500];
    sprintf(tmp,"%s_%f.jpeg",s.c_str(),systemTimer.Get());
    image -> Write(tmp);
    delete image;
}

void DataLogger::TrackDouble(double* d,string name) {
    dVals.push_back(d);
    previousDVals.push_back(*d);
    double time = systemTimer.Get();
    char buffer[500];
    sprintf(buffer,"loggedData/%f_%s_Double.txt",time,name.c_str());
    File *f = new File(buffer);
    dValFiles.push_back(f);
    char buffer2[500];
    sprintf(buffer2,"Double Tracking for %s \n Start Time: %f",name.c_str(),time);
    dValFiles.at(dValFiles.size() - 1) -> addLine(buffer2);
}

void DataLogger::updateDoubleTracking() {
    for(unsigned int i = 0; i < dVals.size(); i++)
    {
        previousDVals.at(i) = *dVals.at(i);
        char buffer[500];
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
            sprintf(buffer,"End Time: %f",systemTimer.Get());
            dValFiles.at(i) -> addLine(buffer);
            dValFiles.erase(dValFiles.begin() + i);
        }
    }
}

void DataLogger::TrackInt(int* i,string name) {
    iVals.push_back(i);
    previousIVals.push_back(*i);
    double time = systemTimer.Get();
    char buffer[500];
    sprintf(buffer,"loggedData/%f_%s_Int.txt",time,name.c_str());
    File *f = new File(buffer);
    iValFiles.push_back(f);
    char buffer2[500];
    sprintf(buffer2,"Int Tracking for %s \n Start Time: %f",name.c_str(),time);
    iValFiles.at(iValFiles.size() - 1) -> addLine(buffer2);
}

void DataLogger::updateIntTracking() {
    for(unsigned int i = 0; i < dVals.size(); i++)
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
            sprintf(buffer,"End Time: %f",systemTimer.Get());
            iValFiles.at(i) -> addLine(buffer);
            iValFiles.erase(iValFiles.begin() + i);
        }
    }
}


void DataLogger::TrackBool(bool* b,string name) {
    bVals.push_back(b);
    previousBVals.push_back(*b);
    double time = systemTimer.Get();
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
            sprintf(buffer,"End Time: %f",systemTimer.Get());
            bValFiles.at(i) -> addLine(buffer);
            bValFiles.erase(bValFiles.begin() + i);
        }
    }
}

void DataLogger::update() {
    if(iterativeTimer.HasPeriodPassed(UPDATE_RATE_TIME))
    {
        updateDoubleTracking();
        updateIntTracking();
        updateBoolTracking();
    }
}

void DataLogger::update_helper(void* o) {
    ((DataLogger*)o) -> update();
}
