#include "../vars.h"

void auton2(){
  int start = millis();
  motorSlew[4] = 127;
  motorSlew[5] = 127;
  printf("auton1\n");
  runIntake(-120);
  driveStraight(24.0);
  printf("%d\n", motorReq[6]);
  printf("turn to the platform\n");
  turnAngle(-90);
  printf("get on the yellow platform\n");
  driveStraight(95);
  runIntake(0);
  runIndexer(0);
  printf("%d\n",millis()-start);
  printf("autonDone\n");
  motorSlew[4] = 30;
  motorSlew[6] = 30;

}
