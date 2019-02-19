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
    debugMotor(0, driveLeft1, "driveLeft1", 0);
    debugMotor(1, driveLeft2, "driveLeft2", 1);
    debugMotor(2, driveRight1, "driveRight1", 2);
    debugMotor(3, driveRight2, "driveRight2", 3);
    delay(20);
  }

}
