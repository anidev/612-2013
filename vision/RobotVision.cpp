#include <cstdio>
#include <vector>
#include <Task.h>
#include <Timer.h>
#include <Vision/ColorImage.h>
#include <Vision/BinaryImage.h>
#include <nivision.h>
#include "vision.h"
#include "visionVars.h"
#include "../target.h"
#include "../Hardware.h"
#include "RobotVision.h"

const char* const TABLE_NAME="DriverVision";

RobotVision::RobotVision(AxisCamera* camera):camera(camera),
                                             vision_task("RobotVision Task",(FUNCPTR)&RobotVision::vision_entry) {
}

RobotVision::~RobotVision() {
    if(continuousRunning) {
        stopContinuous();
    }
}

void RobotVision::startContinuous() {
    continuousRunning=true;
    vision_task.Start();
}

void RobotVision::stopContinuous() {
    vision_task.Stop();
    continuousRunning=false;
}

std::vector<Target>* RobotVision::getTargetsNow() {
//    std::vector<Target>* targets=new std::vector<Target>();
/*    if(table==NULL) {
        table=netcom->get_table(TABLE_NAME);
    }
    if(camera()==NULL||table==NULL) {
        std::printf("Failed to acquire camera or table.\n");
        delete targets;
        return NULL;
    }*/
    ColorImage* image=camera->GetImage();
    BinaryImage* binImage=NULL;
    if(threshold_type==RGB) {
        binImage=image->ThresholdRGB(color1_low,color1_high,color2_low,color2_high,color3_low,color3_high);
    }
    else if(threshold_type==HSL)
    {
        binImage=image->ThresholdHSL(color1_low,color1_high,color2_low,color2_high,color3_low,color3_high);
    }
    else
    {
        binImage=image->ThresholdHSV(color1_low,color1_high,color2_low,color2_high,color3_low,color3_high);
    }
    BinaryImage* convexImage=binImage->ConvexHull(false);
    ParticleFilterCriteria2 criteria[]={{criteria_type,criteria_min,criteria_max,false,false}};
    BinaryImage* filteredImage=convexImage->ParticleFilter(criteria,1);
    int numParticles=filteredImage->GetNumberParticles();
/*    for(int i=0;i<numParticles;i++) {
        Target::type_t type=determineType(filteredImage,i);
        double distance=0.0; // TODO fix
        ParticleAnalysisReport report=filteredImage->GetParticleAnalysisReport(i);
        int x_off=report.center_mass_x-320;
        int y_off=report.center_mass_y-240;
        Target target(distance,x_off,y_off,type,report);
        targets->push_back(target);
    }*/
    delete filteredImage;
    delete convexImage;
    std::printf("# particles: %d\n",numParticles);
    delete binImage;
    delete image;
    return NULL; //targets;
}

int RobotVision::vision_entry(void* obj) {
    RobotVision* robot=(RobotVision*)obj;
    while(true) {
        vision::processContinuous(robot->getTargetsNow());
    }
    return 0;
}
