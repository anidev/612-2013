#include <Vision2009/VisionAPI.h>
#include "target.h"

int Target::getPriority()
{
    return priority;
}
float Target::getDistance()
{
    if(distance > 0)
        return distance;
    return 0;
}
int Target::getXOff()
{
    return x_off;
}
int Target::getYOff()
{
    return y_off;
}
Target::type_t Target::getType()
{
    return type;
}
Target::Target(float _distance,int _xoff,int _yoff,type_t _type,ParticleAnalysisReport _report)
{
    distance = _distance;
    x_off = _xoff;
    y_off = _yoff;
    report = _report;
    type = _type;
    determinePriority(type,distance);
}
void Target::determinePriority(Target::type_t,float distanceT)
{
    // TODO actually get realistic priority calculations
    priority = 0;
}
ParticleAnalysisReport Target::getReport() {
    return report;
}

// aspect ratio includes 4in on each side for tape
TargetInfo targetsInfo[]={
    {31.0,      37.0/32.0}, // LOW.  29x24
    {793.0/8.0, 62.0/29.0}, // MID,  54x21
    {881.0/8.0, 62.0/21.0}, // HIGH, 54x12
    {0.0,       -1.0},      // PYRAMID TODO
    {-1.0,      -1.0}       // UNKNOWN
};
