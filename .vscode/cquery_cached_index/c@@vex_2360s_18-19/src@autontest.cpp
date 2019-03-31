#include "vars.h"

void autonTest(){
  int start = millis();
  printf("Auton Test\n");
  getBall();
  printf("first part done");


  delay(20);

  printf("%d\n",millis()-start);
  printf("autonDone\n");
  while(true){
    leftDrive.debug(3);
    rightDrive.debug(4);
    delay(20);
  }

}
