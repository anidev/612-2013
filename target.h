#ifndef TARGET_H
#define TARGET_H

class Target{
private:
    int priority;
    int distance;
    int angle;
    void determinePriority(int,int);

public:
    Target(int,int,int);

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
    int getDistance();
    int getAngle();
};
#endif
