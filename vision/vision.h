#ifndef VISION_H
#define VISION_H

#include <cmath>
#include <vector>
#include <Vision/BinaryImage.h>
#include "../target.h"

class vision
{
    public:
        virtual void startContinuous()=0;
        virtual void stopContinuous()=0;
        virtual std::vector<Target>* getTargetsNow()=0;
        double getGroundDist(double,double);
    protected:
        vision();
        virtual ~vision();
        static Target::type_t determineType(BinaryImage*,unsigned int);
        static void processContinuous(std::vector<Target>*);
};
#endif
