#include "vision.h"
#include <vector>
#include "../target.h"
#include <Vision/AxisCamera.h>
#include <Timer.h>
#include <nivision.h>
#include "../612.h"

vision::vision(){
}

vision::~vision(){
}

double vision::getGroundDist(double angle, double target_height) {
    double length = 9.06;
    double base = 18.64;
    double added_height = (angle > 0)?length+(length*sin(angle*M_PI/180)):length-(length*sin(angle*M_PI/180));
    double camera_height = base + added_height; 
    return (target_height - camera_height) / tan(angle*M_PI/180);
}

Target::type_t vision::determineType(BinaryImage* image,int index) {
    Image* imaq=image->GetImaqImage();
    double equivWidth = 0.0;
    double equivHeight = 0.0;
    imaqMeasureParticle(imaq,index,0,IMAQ_MT_EQUIVALENT_RECT_LONG_SIDE,&equivWidth);
    imaqMeasureParticle(imaq,index,0,IMAQ_MT_EQUIVALENT_RECT_SHORT_SIDE,&equivHeight);
    double aspect = equivWidth/equivHeight;
    double minDiff = 1.0;
    int closestType = (int)Target::UNKNOWN;
    for(int i=0;i<3;i++) {
        double aspectDiff = std::fabs(aspect-targetsInfo[i].aspect);
        if(aspectDiff < minDiff) {
            minDiff = aspectDiff;
            closestType = i;
        }
    }
    return (Target::type_t)closestType;
}

void vision::processContinuous(std::vector<Target>* targets) {
    // TODO DO STUFF in vision::processContinuous
    delete targets; // should all be new-allocated
}
