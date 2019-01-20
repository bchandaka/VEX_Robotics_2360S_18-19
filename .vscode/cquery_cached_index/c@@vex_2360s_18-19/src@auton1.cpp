#include "../vars.h"

void auton1(){
  delay(200);
  int start = millis();
  motorSlew[4] = 127;
  motorSlew[5] = 127;
  printf("auton1\n");
  getBall();
  shootHighFlags();
  shootLowFlag();
  platform();
  printf("%d\n",millis()-start);
  runIntake(0);
  runIndexer(0);
  printf("autonDone\n");
  motorSlew[4] = 30;
  motorSlew[6] = 30;
}
