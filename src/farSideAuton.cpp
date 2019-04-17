#include "vars.h"

void farSidePlat(){
  delay(200);
  int start = millis();

  getFarBall();
  farPlatform();
  printf("%d\n",millis()-start);

  printf("autonDone\n");
}

void farSide(){
  delay(200);
  int start = millis();

  getFarBall();
  shootHighMiddleFlag();
  placeSecondCap();
  printf("%d\n",millis()-start);
  printf("autonDone\n");

}
