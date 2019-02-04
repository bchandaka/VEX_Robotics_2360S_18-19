#include "vars.h"

void getBall(){
  runIntake(-120);
  driveStraight(43.0);
  printf("%d\n", motorReq[6]);
  printf("moving backward\n");
  runFlywheel(110);
  driveStraight(-34.0);
}
void shootHighFlags(){
  //face the flags
  turnAngle(-90);
  delay(150);
  printf("Shoot the top flag\n");
  runIndexer(127);
  delay(300);
  runIndexer(0); //Starting here
  printf("Lower FlyWheel Speed\n");
  runFlywheel(98);
  delay(900);
  printf("Shoot the middle flag\n");
  runIndexer(127);
  delay(400);
  runFlywheel(0);
}
void shootLowFlag(){
  printf("Ram the bottom flag\n");
  driveStraight(25);
  turnAngle(-3);
  driveStraight(15);
  printf("back out of flag and come back\n");
  driveStraight(-15);
  turnAngle(3);
}

void nearPlatform(){
  printf("coming back to platform\n");
  driveStraight(-43);
  printf("face platform\n");
  turnAngle(90);
  printf("get on the red platform\n");
  driveStraight(49);
}
void farPlatform(){
  printf("coming back to platform\n");
  driveStraight(-52);
  printf("face platform\n");
  turnAngle(90);
  printf("get on the yellow platform\n");
  driveStraight(45);
}
