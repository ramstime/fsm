#include <assert.h>
#include "Motor.h"
#include<iostream>
using namespace std;
 
// halt motor external event
void Motor::Halt(void)
{
    // given the Halt event, transition to a new state based upon 
    // the current state of the state machine
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (EVENT_IGNORED)  // ST_Idle
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)  // ST_Stop
        TRANSITION_MAP_ENTRY (ST_STOP)        // ST_Start
        TRANSITION_MAP_ENTRY (ST_STOP)        // ST_ChangeSpeed
    END_TRANSITION_MAP(NULL)
}
 
// set motor speed external event
void Motor::SetSpeed(MotorData* pData)
{
    BEGIN_TRANSITION_MAP                      // - Current State -
        TRANSITION_MAP_ENTRY (ST_START)       // ST_Idle       
        TRANSITION_MAP_ENTRY (CANNOT_HAPPEN)  // ST_Stop       
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)// ST_Start      
        TRANSITION_MAP_ENTRY (ST_CHANGE_SPEED)// ST_ChangeSpeed
    END_TRANSITION_MAP(pData)
}
 
// state machine sits here when motor is not running
void Motor::ST_Idle() 
{
    cout<<"Motor::ST_Idle"<<endl;
}
 
// stop the motor 
void Motor::ST_Stop()
{
    // perform the stop motor processing here
    // transition to ST_Idle via an internal event
    InternalEvent(ST_IDLE);
    cout<<"Motor::ST_Stop"<<endl;
}
 
// start the motor going
void Motor::ST_Start(MotorData* pData)
{
    // set initial motor speed processing here
    cout<<"Motor::ST_Start"<<endl;
}
 
// changes the motor speed once the motor is moving
void Motor::ST_ChangeSpeed(MotorData* pData)
{
    // perform the change motor speed to pData->speed here
    cout<<"Motor::ST_ChangeSpeed"<<endl;
}

main()
{
    Motor car;
    MotorData *pData = new MotorData;
    pData->speed= 400;
    car.SetSpeed(pData);
    MotorData *pcData = new MotorData;
    pcData->speed = 10;
    car.SetSpeed(pcData);
    car.Halt();
    
}