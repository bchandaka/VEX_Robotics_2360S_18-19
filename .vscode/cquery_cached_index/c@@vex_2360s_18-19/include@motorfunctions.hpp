#ifndef _PROS_MOTORFUNCTIONS_HPP
#define _PROS_MOTORFUNCTIONS_HPP
#include "slewRate.hpp"
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
void runDescorer(int volts){
  motorReq[7] = volts;
}
#endif
