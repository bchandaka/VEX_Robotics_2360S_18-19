#include "vars.h"

void nearSidePlat(){
  int start = millis();
  printf("auton1\n");
  getBall();
  shootHighFlags();
  shootLowFlag();
  nearPlatform();
  printf("%d\n",millis()-start);
  intake.run(0);
  indexer.run(0);
  printf("autonDone\n");
}
void nearSide(){
  int start = millis();
  printf("auton1\n");
  getBall();
  shootHighFlags();
  shootLowFlag();
  flipSecondCap();
  shootMiddleLowFlag();
  printf("%d\n",millis()-start);
  intake.run(0);
  indexer.run(0);
  printf("autonDone\n");
}
