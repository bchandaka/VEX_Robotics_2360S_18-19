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
  driveStraight(-33.0);
  //face the flags
  turnAngle(-90);
  driveStraight(10.0);
  printf("Shoot the top flag\n");
  runIndexer(127);
  delay(300);
  runIndexer(0); //Starting here
  printf("Lower FlyWheel Speed\n");
  runFlywheel(90);
  delay(900);
  printf("Shoot the middle flag\n");
  runIndexer(127);
  delay(500);
  runIndexer(0);
  runFlywheel(0);

  printf("Ram the bottom flag\n");
  turnAngle(-3);
  driveStraight(38);
  printf("back out of flag and come back\n");
  driveStraight(-38);
  turnAngle(3);
  printf("coming back to platform\n");
  driveStraight(-32);
  printf("face platform\n");
  turnAngle(90);
  printf("get on the platform\n");
  driveStraight(38);
  printf("%d\n",millis()-start);
  /*runIntake(-127);
  driveStraight(18.0);
  runIntake(0);
  printf("Shoot the Middle Flag\n");
  runIndexer(127);
  delay(700);
  runIndexer(0);
  runFlywheel(0);
  driveStraight(10.0);
  turnAngle(-10);
  printf("Ram the low Flag\n");
  driveStraight(7.0);*/
  printf("autonDone\n");
  motorSlew[4] = 15;
  motorSlew[6] = 15;

}
