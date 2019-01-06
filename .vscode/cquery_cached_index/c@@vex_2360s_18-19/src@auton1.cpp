#include "../vars.h"

void auton1(){
  int start = millis();
  motorSlew[4] = 127;
  motorSlew[5] = 127;
  printf("auton1\n");
  runIntake(-120);
  driveStraight(43.0);
  printf("%d\n", motorReq[6]);
  printf("moving backward\n");
  runFlywheel(127);
  driveStraight(-34.0);
  //face the flags
  turnAngle(-90);
  driveStraight(10.0);
  printf("Shoot the top flag\n");
  runIndexer(127);
  delay(300);
  runIndexer(0); //Starting here
  printf("Lower FlyWheel Speed\n");
  runFlywheel(93);
  delay(900);
  printf("Shoot the middle flag\n");
  runIndexer(127);
  runFlywheel(0);

  printf("Ram the bottom flag\n");
  driveStraight(25);
  turnAngle(-10);
  driveStraight(10);
  printf("back out of flag and come back\n");
  driveStraight(-10);
  turnAngle(10);


  printf("coming back to platform\n");
    driveStraight(-56);
  printf("face platform\n");
  turnAngle(90);
  printf("get on the yellow platform\n");
  driveStraight(50);
  printf("%d\n",millis()-start);
  runIntake(0);
  runIndexer(0);
  printf("autonDone\n");
  motorSlew[4] = 30;
  motorSlew[6] = 30;

}
