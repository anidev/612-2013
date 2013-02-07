#ifndef NETWORKCOM_H_INCLUDED
#define NETWORKCOM_H_INCLUDED

#include <networktables/NetworkTable.h>

class NetworkCom {
public:
    NetworkCom();
    ~NetworkCom();
private:
    NetworkTable* Main;
    NetworkTable* Tracking;
    NetworkTable* Gunner;
    NetworkTable* Autonomous;
};

#endif // NETWORKCOM_H_INCLUDED
