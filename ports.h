#ifndef PORTS_H
#define PORTS_H

#include <Joystick.h>
#include <RobotDrive.h>

class DriveTrain;
class auto_encoders;
class shifter;
class Lift;
class Shooter;
class EnhancedJoystick;
class AutoShooter;

typedef int canport_t;

struct hw_info {
    UINT8 moduleNumber;
    UINT8 channel;
};

extern EnhancedJoystick left_joystick;
extern EnhancedJoystick right_joystick;
extern EnhancedJoystick gunner_joystick;
extern DriveTrain drive_train;
extern shifter shift;
extern Lift angleAdjuster;
extern Shooter shooter;
extern AutoShooter auto_shoot;
//lifter
static const hw_info launch_angle_pot =  {1, 1}; // suzie;()
static const hw_info lift_motor =        {2, 1}; // suzie;(2,3) - New Robot
//LED relay
static const hw_info led =               {2, 1}; // practice board
//Shifter servos
static const hw_info side1 =             {1, 6}; // suzie
static const hw_info side2 =             {2, 4}; // suzie
//Drive Motors
static const hw_info left_front_motor =  {2, 2}; // suzie
static const hw_info left_rear_motor =   {2, 3}; // suzie
static const hw_info right_front_motor = {1, 3}; // suzie
static const hw_info right_rear_motor =  {1, 4}; // suzie
//Encoders
static const hw_info right_encoder1 =    {1, 1}; // suzie
static const hw_info right_encoder2 =    {1, 2}; // suzie
static const hw_info left_encoder1 =     {2, 4}; // suzie
static const hw_info left_encoder2 =     {2, 5}; // suzie
//Shooter motor
static const hw_info launcher_wheel_1 =  {1, 1}; // suzie
static const hw_info launcher_wheel_2 =  {1, 2}; // suzie
//static const hw_info feeder_belt =     {1,10}; // dummy3
static const hw_info feeder_1 =          {2, 1}; // suzie (replacement of feeder_belt)
static const hw_info feeder_2 =          {2, 2}; // suzie (replacement of feeder_belt)
static const hw_info launcher_sensor =   {1,10}; // suzie
#endif
