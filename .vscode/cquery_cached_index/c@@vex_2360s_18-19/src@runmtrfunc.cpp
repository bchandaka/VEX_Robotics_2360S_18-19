#include "vars.h"
//------------------Motor Functions------------------
void runDriveLeft(int volts){
  motorReq[0] = volts;
  motorReq[1] = -volts;
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
void runLift(int volts){
  motorReq[7] = volts;
}
