#include <vector>
#include <Task.h>
#include "vision.h"
#include "../target.h"
#include "../ports.h"
#include "../612.h"
#include "DriverVision.h"

const char* const TABLE_NAME="DriverVision";

DriverVision::DriverVision():vision_task("DriverVision task",(FUNCPTR)&DriverVision::vision_entry) {
}

void DriverVision::startContinuous() {
    vision_task.Start();
}

void DriverVision::stopContinuous() {
    vision_task.Stop();
}

std::vector<Target>* DriverVision::getTargetsNow() {
    std::vector<Target>* targets=new std::vector<Target>();
    if(table==NULL) {
        table=netcom->get_table(TABLE_NAME);
    }
    if(camera()==NULL||table==NULL) {
        std::printf("Failed to acquire camera or table.\n");
        delete targets;
        return NULL;
    }
    int num_targets=(int)table->GetNumber("NumTargets",0.0);
/*    for(int i=0;i<num_targets;i++) {
        NetworkTable* target_table=table->GetSubTable(
        double angle=
    }*/
    return NULL;
}

int DriverVision::vision_entry(void* obj) {
    DriverVision* driver=(DriverVision*)obj;
    while(true) {
        vision::processContinuous(driver->getTargetsNow());
    }
}
