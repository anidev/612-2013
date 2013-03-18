#include "autonomous.h"
#include "main.h"
#include "EnhancedShooter.h"
#include "EnhancedRobotDrive"

void doAutonomous(void* o) {
    /*        Psuedo Code
     *  1) Set Angle
     *  2) Set Speed
     *  3) If at both then feed
     *  4) repeat #3
     */
     //settings
     static const unsigned float SPEED = 60.0f;
     static const unsigned float ANGLE = 27.0f;
     
     //Initialize Pointers
     robot_class* robot = (robot_class*)o;
     EnhancedShooter* shooter = robot -> shooter;
     
     //Set shooter Targets
     shooter -> setAngle(ANGLE);
     shooter -> setSpeed(SPEED);
     
     while(!shooter -> atAngle(ANGLE)) {} //Wait for at angle
     shooter -> stopLift(); //Stop PID when at speed
     
     while(true) //yes i know not great coding practice
     {
         if(shooter -> atSpeed(SPEED))
         {
             shooter -> setFeeder(EnhancedShooter::FORWARD);
         }
         //No need to stop the update funct will stop after one shot and if at speed it will not stop
     }
}

void disableAuto(void* o) {
    ((robot_class*)o) -> Autonomous.Stop();
}
