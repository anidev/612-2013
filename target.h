#include "
#ifndef TARGET_H
#define TARGET_H

class Target{
    private:
    int priortity;
    int distance;
    int angle;
    void determinePrority(int angleFromShooterT,int heightOfGoalT, int widthOfGoalT );

    public:
    Target();

    enum type
    {
        UNKNOWN,
        TOPGOAL,
        MIDDLELEFTGOAL,
        MIDDLERIGHTGOAL,
        BOTTOMGOAL,
        PYRAMIDGOAL,
    };
    int getPriority();

};
#endif
