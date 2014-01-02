#include "PIDCounter.h"

PIDCounter::PIDCounter(UINT8 module,UINT32 channel):Counter(module,channel){
}
double PIDCounter::PIDGet() {
        return 1.0/GetPeriod();
}
