#include <vector>
#include <Task.h>
#include "vision.h"
#include "../target.h"
#include "../ports.h"
#include "../612.h"
#include "DriverVision.h"

const char* const TABLE_NAME = "DriverVision";

DriverVision::DriverVision():vision_task("DriverVision task",(FUNCPTR)&DriverVision::vision_entry) {
}

void DriverVision::startContinuous() {
    startRemoteContinuous();
    vision_task.Start();
}

void DriverVision::stopContinuous() {
    vision_task.Stop();
    stopRemoteContinuous();
}

void DriverVision::setRemoteEnabled(bool enabled) {
    if(table == NULL) 
    {
        table = netcom -> get_table(TABLE_NAME);
    }
    if(table == NULL) 
    {
        std::printf("Failed to acquire camera or table.\n");
        return;
    }
    table -> PutBoolean("Enabled",enabled);
}

void DriverVision::startRemoteContinuous() {
    setRemoteEnabled(true);
}

void DriverVision::stopRemoteContinuous() {
    setRemoteEnabled(false);
}

std::vector<Target>* DriverVision::getTargetsNow() {
    std::vector<Target>* targets=new std::vector<Target>();
    if(table == NULL) 
    {
        table = netcom -> get_table(TABLE_NAME);
    }
    if(camera() == NULL||table == NULL) 
    {
        std::printf("Failed to acquire camera or table.\n");
        delete targets;
        return NULL;
    }
    int num_targets = (int)table -> GetNumber("NumTargets",0.0);
     for(int i = 0;i < num_targets;i++) 
     {
        char target_table_name[64];
        sprintf(target_table_name,"Target%d",i);
        NetworkTable* target_table = table -> GetSubTable(target_table_name);
        double distance = target_table -> GetNumber("Distance",-1.0);
        int x_off = (int)target_table -> GetNumber("Xoff",0.0);
        int y_off = (int)target_table -> GetNumber("Yoff",0.0);
        Target::type_t type = (Target::type_t)target_table -> GetNumber("Type",(double)Target::UNKNOWN);
        ParticleAnalysisReport report;
        Target target(distance,x_off,y_off,type,report);
        targets -> push_back(target);
    }
    return targets;
}

int DriverVision::vision_entry(void* obj) {
    DriverVision* driver = (DriverVision*)obj;
    while(true) 
    {
        vision::processContinuous(driver -> getTargetsNow());
    }
}
