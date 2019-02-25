#include "vars.h"

void farSidePlat(){
  delay(200);
  int start = millis();
  motorSlew[4] = 127;
  motorSlew[5] = 127;
  getFarBall();
  placeSecondCap();
  shootHighMiddleFlag();
  farPlatform();
  printf("%d\n",millis()-start);

  printf("autonDone\n");
  motorSlew[4] = 30;
  motorSlew[6] = 30;

}

void farSide(){
  delay(200);
  int start = millis();
  motorSlew[4] = 127;
  motorSlew[5] = 127;
  getFarBall();
  placeSecondCap();
  shootMiddleFlags();
  printf("%d\n",millis()-start);
  printf("autonDone\n");
  motorSlew[4] = 30;
  motorSlew[6] = 30;

}
