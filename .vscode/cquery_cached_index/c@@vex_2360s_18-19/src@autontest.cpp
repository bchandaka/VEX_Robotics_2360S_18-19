#include "vars.h"

void autonTest(){
  int start = millis();
  printf("Auton Test\n");
  printf("first part done");
  turnAngle(-90);
  lcd::print(7,"%d",millis()-start);
  printf("autonDone\n");
  while(true){
    leftDrive.debug(3);
    rightDrive.debug(4);
    lcd::print(5, "Gyro: %f", gyro.get_value());
    delay(20);
  }
}
