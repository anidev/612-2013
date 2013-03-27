#ifndef PIDCOUNTER_H
#define PIDCOUNTER_H

#include <Counter.h>
#include <PIDSource.h>

class PIDCounter : public Counter, public PIDSource {
public:
    PIDCounter(UINT8,UINT32);
    double PIDGet();
};

#endif // PIDCOUNTER_H
