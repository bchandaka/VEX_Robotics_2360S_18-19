#include "vars.h"

void farSidePlat(){
  delay(200);
  int start = millis();

  getFarBall();
  placeSecondCap();
  shootHighMiddleFlag();
  farPlatform();
  printf("%d\n",millis()-start);

  printf("autonDone\n");
}

void farSide(){
  delay(200);
  int start = millis();

  getFarBall();
  placeSecondCap();
  shootMiddleFlags();
  printf("%d\n",millis()-start);
  printf("autonDone\n");

}
