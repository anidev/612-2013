#include "vision.h"
#include <vector>
#include "target.h"
#include <Vision/AxisCamera.h>
#include <Timer.h>
#include <nivision.h>

vision::vision():continuousRunning(false) {
}

vision::~vision(){
}

double vision::getGroundDist(double angle, double target_height) {
    double length = 9.06;
    double base = 18.64;
    double added_height = (angle > 0)?length+(length*sin(angle)):length-(length*sin(angle));
    double camera_height = base + added_height; 
    return (target_height - camera_height) / tan(angle);
}

Target::type_t vision::determineType(BinaryImage* image,int index) {
    Image* imaq=image->GetImaqImage();
    double equivWidth=0.0;
    double equivHeight=0.0;
    imaqMeasureParticle(imaq,index,0,IMAQ_MT_EQUIVALENT_RECT_LONG_SIDE,&equivWidth);
    imaqMeasureParticle(imaq,index,0,IMAQ_MT_EQUIVALENT_RECT_SHORT_SIDE,&equivHeight);
    double aspect=equivWidth/equivHeight;
    double minDiff=1.0;
    int closestType=(int)Target::UNKNOWN;
    for(int i=0;i<3;i++) {
        double aspectDiff=std::fabs(aspect-targetsInfo[i].aspect);
        if(aspectDiff<minDiff) {
            minDiff=aspectDiff;
            closestType=i;
        }
    }
    return (Target::type_t)closestType;
}

bool vision::isContinuousRunning() {
    return continuousRunning;
}

void vision::processContinuous(std::vector<Target>* targets) {
    static Timer output;
    static bool outputStarted=false;
    if(!outputStarted) {
        output.Start();
        outputStarted=true;
    }
    if(output.Get()<0.5) {
        if(targets!=NULL) {
            delete targets;
        }
        return;
    }
    output.Reset();
    if(targets==NULL) {
//        printf("time: %f\n",output.Get());
        printf("targets: none\n");
        return;
    }
    printf("targets: %d\n",targets->size());
    delete targets; // should all be new-allocated
}

int vision::vision_entry(void* obj) {
    vision* engine=(vision*)obj;
    while(true) {
        vision::processContinuous(engine->getTargetsNow());
    }
    return 0;
}
