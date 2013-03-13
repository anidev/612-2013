#ifndef TARGET_H
#define TARGET_H

#include <Vision2009/VisionAPI.h>

class Target {
public:
    enum type_t {
        BOTTOMGOAL=0,
        MIDDLEGOAL=1,
        TOPGOAL=2,
        PYRAMIDGOAL=3,
        UNKNOWN=4,
    };
    Target(unsigned float,int,int,type_t,ParticleAnalysisReport);
    int getPriority();
    unsigned float getDistance();
    int getXOff();
    int getYOff();
    type_t getType();
    ParticleAnalysisReport getReport();

private:
    int x_off;
    int y_off;
    double distance;
    int priority;
    type_t type;
    ParticleAnalysisReport report;
    void determinePriority(type_t,unsigned float);
};

struct TargetInfo {
    const double height;
    const double aspect; // x/y
};

extern TargetInfo targetsInfo[];

#endif
