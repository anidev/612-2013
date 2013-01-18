#include "Target.h"

Target::getPriority()
{
    return priority;

}
Target::Target()
{
    prority=0;
    distance=0;
    angle=0;
}
Target::determinePrority(int angleFromShooterT,int distanceT)
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

