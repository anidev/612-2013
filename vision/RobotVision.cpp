#include <cstdio>
#include <vector>
#include <Task.h>
#include <Timer.h>
#include <Vision/ColorImage.h>
#include <Vision/BinaryImage.h>
#include <nivision.h>
#include "vision.h"
#include "visionVars.h"
#include "target.h"
#include "../Hardware.h"
#include "RobotVision.h"

const char* const TABLE_NAME="RobotVision";

RobotVision::RobotVision(AxisCamera* camera):camera(camera),
                                             vision_task("RobotVision Task",(FUNCPTR)&vision::vision_entry) {
    printf("engine started\n");
}

RobotVision::~RobotVision() {
    if(continuousRunning) {
        stopContinuous();
    }
}

void RobotVision::startContinuous() {
    printf("starting continuous\n");
    continuousRunning=true;
    vision_task.Start((UINT32)this);
}

void RobotVision::stopContinuous() {
    vision_task.Stop();
    continuousRunning=false;
}

std::vector<Target>* RobotVision::getTargetsNow() {
    std::vector<Target>* targets=new std::vector<Target>();
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
    printf("# particles: %d\n",numParticles);
    for(int i=0;i<numParticles;i++) {
//        Target::type_t type=determineType(filteredImage,i);
        double distance=0.0; // TODO fix
        ParticleAnalysisReport report=filteredImage->GetParticleAnalysisReport(i);
        int x_off=report.center_mass_x-320;
        int y_off=report.center_mass_y-240;
        Target target(distance,x_off,y_off,Target::UNKNOWN,report);
        targets->push_back(target);
    }
    delete filteredImage;
    delete convexImage;
    delete binImage;
    delete image;
    return NULL; //targets;
}
