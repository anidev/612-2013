#include "PIDCounter.h"

PIDCounter::PIDCounter(UINT8 module,UINT32 channel):Counter(module,channel),source(Frequency) {
}

void PIDCounter::setSource(Source newSource) {
    source=newSource;
}

double PIDCounter::PIDGet() {
    double ret=0.0;
    switch(source) {
    case Period:
        ret=GetPeriod();
        break;
    case Frequency:
        ret=1.0/GetPeriod();
        break;
    }
    return ret;
}
