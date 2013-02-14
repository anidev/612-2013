#ifndef PIDCOUNTER_H
#define PIDCOUNTER_H

#include <Counter.h>
#include <PIDSource.h>

class PIDCounter : public Counter, public PIDSource {
public:
    enum Source {
        Period,Frequency
    };
    PIDCounter(UINT8,UINT32);
    void setSource(Source);
    double PIDGet();
private:
    Source source;
};

#endif // PIDCOUNTER_H
