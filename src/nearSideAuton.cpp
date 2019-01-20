#include "../vars.h"

void nearSidePlat(){
  delay(200);
  int start = millis();
  motorSlew[4] = 127;
  motorSlew[5] = 127;
  printf("auton1\n");
  getBall();
  shootHighFlags();
  shootLowFlag();
  nearPlatform();
  printf("%d\n",millis()-start);
  runIntake(0);
  runIndexer(0);
  printf("autonDone\n");
  motorSlew[4] = 30;
  motorSlew[6] = 30;
}
void nearSide(){
  delay(200);
  int start = millis();
  motorSlew[4] = 127;
  motorSlew[5] = 127;
  printf("auton1\n");
  getBall();
  shootHighFlags();
  shootLowFlag();
  nearPlatform();
  printf("%d\n",millis()-start);
  runIntake(0);
  runIndexer(0);
  printf("autonDone\n");
  motorSlew[4] = 30;
  motorSlew[6] = 30;
}
