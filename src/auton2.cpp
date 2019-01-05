#include "../vars.h"

void auton2(){
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
  driveStraight(-28);
  runIntake(120);
  printf("turn towards the cap\n");
  turnAngle(93);
  printf("drive the cap\n");
  driveStraight(20);
  printf("%d\n",millis()-start);
  printf("autonDone\n");
  motorSlew[4] = 15;
  motorSlew[6] = 15;

}
