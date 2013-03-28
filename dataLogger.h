#ifndef DATALOGGER_H
#define DATALOGGER_H

#include "EnhancedShooter.h"
#include "EnhancedJoystick.h"

class DataLogger {
public:
    DataLogger(EnhancedShooter*,void*);
private:
    EnhancedJoystick* driver;
    EnhancedShooter* shooter;
    static void successLog(void*);
};

#endif
