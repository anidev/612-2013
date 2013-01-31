#include "target.h"

int Target::getPriority()
{
    return priority;
}
int Target::getDistance()
{
    return distance;
}
int Target::getAngle()
{
    return angle;
}
Target::Target(int _priority,int _distance,int _angle)
{
    priority=_priority;
    distance=_distance;
    angle=_angle;
    determinePriority(angle,distance);
}
void Target::determinePriority(int angleFromShooterT,int distanceT)
{
    angle=angleFromShooterT;
    distance=distanceT;
    if(distance==0/*Value for the five point goal*/&&angleFromShooterT==0/*value for the five point goal*/)
    {
        priority=1;
        //add shooter methond
    }
    if(distance==0/*Value for the four point goals*/&&angleFromShooterT==0/*value for the four point goals*/)
    {
        priority=2;
        //add shooter methond
    }
    if(distance==0/*Value for the three point goal*/&&angleFromShooterT==0/*value for the three point goal*/)
    {
        priority=3;
        //add shooter methond
    }
}

