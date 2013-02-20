#include <vector>
#include <Task.h>
#include <Vision/ColorImage.h>
#include <Vision/BinaryImage.h>
#include <nivision.h>
#include "vision.h"
#include "visionVars.h"
#include "../target.h"
#include "../ports.h"
#include "RobotVision.h"

const char* const TABLE_NAME="DriverVision";

RobotVision::RobotVision():vision_task("RobotVision task",(FUNCPTR)&RobotVision::vision_entry) {
}

void RobotVision::startContinuous() {
    vision_task.Start();
}

void RobotVision::stopContinuous() {
    vision_task.Stop();
}

std::vector<Target>* RobotVision::getTargetsNow() {
    std::vector<Target>* targets=new std::vector<Target>();
    if(table==NULL) {
        table=netcom->get_table(TABLE_NAME);
    }
    if(camera()==NULL||table==NULL) {
        std::printf("Failed to acquire camera or table.\n");
        delete targets;
        return NULL;
    }
    ColorImage* image=camera()->GetImage();
    BinaryImage* binImage=NULL;
    if(threshold_type==RGB) {
        image->ThresholdRGB(color1_low,color1_high,color2_low,color2_high,color3_low,color3_high);
    }
    else if(threshold_type==HSL)
    {
        image->ThresholdHSL(color1_low,color1_high,color2_low,color2_high,color3_low,color3_high);
    }
    else
    {
        image->ThresholdHSV(color1_low,color1_high,color2_low,color2_high,color3_low,color3_high);
    }
    BinaryImage* convexImage=binImage->ConvexHull(false);
    ParticleFilterCriteria2 criteria[]={{criteria_type,criteria_min,criteria_max,false,false}};
    BinaryImage* filteredImage=convexImage->ParticleFilter(criteria,1);
    int numParticles=filteredImage->GetNumberParticles();
    for(int i=0;i<numParticles;i++) {
        Target::type_t type=determineType(filteredImage,i);
        double distance=0.0; // TODO fix
        ParticleAnalysisReport report=filteredImage->GetParticleAnalysisReport(i);
        int x_off=report.center_mass_x-320;
        int y_off=report.center_mass_y-240;
        Target target(distance,x_off,y_off,type,report);
        targets->push_back(target);
    }
    delete filteredImage;
    delete convexImage;
    delete binImage;
    delete image;
    return targets;
}

int RobotVision::vision_entry(void* obj) {
    RobotVision* robot=(RobotVision*)obj;
    while(true) {
        vision::processContinuous(robot->getTargetsNow());
    }
}
