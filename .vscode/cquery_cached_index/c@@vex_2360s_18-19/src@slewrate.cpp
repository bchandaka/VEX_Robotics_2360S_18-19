#include "vars.h"
#include <algorithm>
//-----SlewRateTask-----
int smartMotor::sign(int x) {
    return (x > 0) - (x < 0);
}
void smartMotor::MotorSlewRateTask(void* params){
  while(true){
    for(int motorIndex=0; motorIndex<8; motorIndex++){
        // So we don't keep accessing the internal storage
          smartMotor* motor =  allMotors[ motorIndex ];
          int currentTmp = motor->getCurVel();
          // Update motor value
          if(currentTmp != motor->getReqVel()){
            currentTmp += sign(motor->getReqVel()-currentTmp) *
                          std::clamp(motor->getSlew(), 0, abs(currentTmp-motor->getReqVel()));
          }
          motor->setCurVel(std::clamp(currentTmp, -127, 127));
          // Send it!!!
          (motor->getMtr()).move(motor->getCurVel());
      }
      pros::delay(20);
  }
}
