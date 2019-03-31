/*
#include "smartMotor.h"
#include <algorithm>
#include "../vars.h"
smartMotor::smartMotor(){

smartMotor::smartMotor(int port, motor_gearset_e_t gearset, bool reversed, motor_encoder_units_e_t encoderUnits){
  this->port = port;
  this->slewRate = 15;
  this->reqVel = 0;
  this->currVel = 0;
  Motor mtr(port,gearset,reversed, encoderUnits);
  this->mtrPointer = &mtr;
}
void smartMotor::init(int port, motor_gearset_e_t gearset, bool reversed, motor_encoder_units_e_t encoderUnits){
  this->port = port;
  this->slewRate = 15;
  this->reqVel = 0;
  this->currVel = 0;
  Motor mtr(port,gearset,reversed, encoderUnits);
  this->mtrPointer = &mtr;
}
void smartMotor::run(int vel){
  reqVel = vel;
}
void smartMotor::setCurrVel(int vel){
  currVel = vel;
}
void smartMotor::setSlew(int slew){
  slewRate = slew;
}
int smartMotor::getPort(){
  return port;
}
int smartMotor::getVel(){
  return currVel;
}
Motor smartMotor::getMtr(){
  return *mtrPointer;
}
//---------------------Slew Rate Task--------------------
#define MOTOR_NUM               8
#define MOTOR_MAX_VALUE         127
#define MOTOR_MIN_VALUE         (-127)
#define MOTOR_TASK_DELAY        15      // task 1/frequency in mS (about 66Hz)
#define MOTOR_DEADBAND          10

int sign(int x) {
    return (x > 0) - (x < 0);
}
void MotorSlewRateTask(void* params){
    int motorIndex;
    // run task until stopped
    while( true ){
        // run loop for every motor
        for(motorIndex=0; motorIndex<MOTOR_NUM; motorIndex++){
            // So we don't keep accessing the internal storage
            Motor motorTmp =  motorObj[ motorIndex ];
            // Current motor value
            int currentTmp = motorVolt[motorIndex];
            // Update motor value
						if(currentTmp != motorReq[motorIndex]){
							currentTmp += sign(motorReq[motorIndex]-currentTmp) *
													std::clamp(motorSlew[motorIndex], 0, abs(currentTmp-motorReq[motorIndex]));
            }
						motorVolt[motorIndex] = std::clamp(currentTmp, MOTOR_MIN_VALUE, MOTOR_MAX_VALUE);

						// finally send it!
						motorTmp.move(motorVolt[motorIndex]);
        }
        // Wait approx the speed of motor update
        delay( MOTOR_TASK_DELAY );
    }
}


//------------------Motor Functions------------------
void runDriveLeft(int volts){
  motorReq[0] = -volts;
  motorReq[1] = volts;
}

void runDriveRight(int volts){
  motorReq[2] = volts;
  motorReq[3] = -volts;
}

void runFlywheel(int volts){
  motorReq[4] = volts;
}
void runIndexer(int volts){
  motorReq[5] = volts;
}
void runIntake(int volts){
  motorReq[6] = volts;
}
void runDescorer(int volts){
  motorReq[7] = volts;
}
*/
