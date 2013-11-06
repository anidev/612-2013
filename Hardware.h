#ifndef HARDWARE_H
#define HARDWARE_H

static const char* const CAMERA_IP="10.6.12.11";

typedef unsigned int CANPort;
struct hw_info {
    UINT8 moduleNumber;
    UINT8 channel;
};
//Shifters
static const hw_info leftShifterInfo =   {2,5};
static const hw_info rightShifterInfo =  {2,6};
static constexpr float kleftgear[]  =        {0.2, 0.8};
static constexpr float krightgear[] =        {0.8, 0.2};
//Drive
static const hw_info left_front_motor  = {2,10};
static const hw_info left_rear_motor   = {2,9};
static const hw_info right_front_motor = {2,7};
static const hw_info right_rear_motor  = {2,8};
//Lift
static const CANPort shooterLift =        2;
//Shooter Wheel
static const CANPort shooterWheel =       1;
//Feeder
static const hw_info feederInfo =        {1,1};
//Sensors
static const hw_info FHalEffectInfo =    {1,3};
static const hw_info WHalEffectInfo =    {1,2};
static const hw_info AutoSelectSwitch  = {1,14};
//Relays/Spikes
static const hw_info ledstrip_spike =    {1,2};
static const hw_info ledring_spike =     {1,1};
#endif
