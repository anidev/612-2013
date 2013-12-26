#include <cstdio>
#include <string>
#include <vector>
#include <Task.h>
#include <networktables/NetworkTable.h>
#include <nivision.h>
#include "vision.h"
#include "visionVars.h"
#include "target.h"
#include "DriverVision.h"

std::string TABLE_NAME="PCVision";

DriverVision::DriverVision():table(NULL/*NetworkTable::GetTable(TABLE_NAME)*/),
                             vision_task("DriverVision Task",(FUNCPTR)&vision::vision_entry) {
    printf("engine started\n");
}

DriverVision::~DriverVision() {
    if(continuousRunning) {
        stopContinuous();
    }
}

void DriverVision::startContinuous() {
    printf("starting continuous\n");
    continuousRunning=true;
//    vision_task.Start((UINT32)this);
}

void DriverVision::stopContinuous() {
//    vision_task.Stop();
    continuousRunning=false;
}

std::vector<Target>* DriverVision::getTargetsNow() {
    std::vector<Target>* targets=new std::vector<Target>();
    if(table==NULL) {
        return NULL;
    }
    // Only 1 target for now
    bool available=table->GetBoolean("1/Available",false);
    if(!available) {
        return NULL;
    }
    double distance=0.0; // TODO fix
    int center_x=(int)table->GetNumber("1/CenterX",cam_width/2);
    int center_y=(int)table->GetNumber("1/CenterY",cam_height/2);
    int x_off=center_x-cam_width;
    int y_off=center_y-cam_height;
    ParticleAnalysisReport report;
    Target target(distance,x_off,y_off,Target::UNKNOWN,report);
    targets->push_back(target);
    return targets;
}
