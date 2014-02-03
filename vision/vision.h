#ifndef VISION_H
#define VISION_H

#include <cmath>
#include <vector>
#include <Vision/BinaryImage.h>
#include "target.h"

class vision
{
public:
    virtual ~vision();
    virtual void startContinuous()=0;
    virtual void stopContinuous()=0;
    virtual std::vector<Target>* getTargetsNow()=0;
    bool isContinuousRunning();
    double getGroundDist(double,double);
    static int vision_entry(void*);
protected:
    vision();
    bool continuousRunning;
    static Target::type_t determineType(BinaryImage*,int);
    static void processContinuous(std::vector<Target>*);
};
#endif
