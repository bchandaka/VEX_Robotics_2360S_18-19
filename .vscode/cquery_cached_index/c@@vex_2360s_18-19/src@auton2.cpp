#include "../vars.h"

void auton2(){
  delay(200);
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
  turnAngle(-7);
  driveStraight(10);
  runIntake(0);
  runIndexer(0);
  printf("%d\n",millis()-start);
  printf("autonDone\n");
  motorSlew[4] = 30;
  motorSlew[6] = 30;

}
