#include "vars.h"

void getBall(){
  runIntake(-120);
  runFlywheel(126);
  driveStraight(43.0);
  printf("%d\n", motorReq[6]);
  printf("moving backward!\n");
  driveStraight(-31.0);
}

void shootHighFlags(){
  //face the flags
  turnAngle(-92);
  driveStraight(6);
  runIntake(0);
  delay(100);
  printf("Shoot the top flag!\n");
  runIndexer(126);
  delay(150);
  runIndexer(0);
  printf("Move closer to shoot middle flag!\n");
  runFlywheel(127);
  runIntake(-120);
  driveStraight(21);
  delay(100);
  runIntake(0);
  printf("Shoot the middle flag!\n");
  runIndexer(120);
  delay(400);
  runIndexer(0);
  runFlywheel(0);
}
void shootLowFlag(){
  if(autonBlue){
    printf("Ram the bottom flag!\n");
    turnAngle(-15);
    driveStraight(16);
    printf("back out of flag and come back!\n");
    driveStraight(-16);
    turnAngle(15);
    runIntake(80);
  }
  else{
    printf("Ram the bottom flag!\n");
    turnAngle(-15);
    driveStraight(16);
    printf("back out of flag and come back!\n");
    driveStraight(-16);
    turnAngle(15);
    runIntake(80);
  }
}

void flipSecondCap(){
  driveStraight(-5);
  turnAngle(90);
  driveStraight(22);
}
void shootMiddleLowFlag(){
  if(autonBlue){
    driveStraight(-3);
    runIntake(0);
    turnAngle(-45);
    runIntake(0);
    driveStraight(30);
    turnAngle(-60);
  }
  else{
    driveStraight(-3);
    runIntake(0);
    turnAngle(-45);
    runIntake(0);
    driveStraight(30);
    turnAngle(-60);
  }
}
void nearPlatform(){
  printf("face platform!\n");
  runIntake(-120);
  driveStraight(-47);
  turnAngle(90);

  printf("get on the red platform!\n");
  driveStraight(57);
}

void getFarBall(){
  runIntake(-120);
  runFlywheel(127);
  driveStraight(43.0);
  printf("%d\n", motorReq[6]);
  printf("moving backward!\n");
  //driveStraight(-32.0);
}
void shootMiddleFlags(){
  runIntake(0);
  turnAngle(-54);
  delay(300);
  printf("Shoot the top flag!\n");
  runIndexer(110);
  delay(200);
  runIndexer(0); //Starting here
  runIntake(-120);
  delay(200);
  printf("Move back to shoot middle flag!\n");
  driveStraight(-6);

  runIntake(0);
  printf("Shoot the middle flag!\n");
  runIndexer(120);
  delay(500);
  runIndexer(0);
  runFlywheel(0);
  driveStraight(6);
}
void shootHighMiddleFlag(){
  if(autonBlue){
  runIntake(0);
  turnAngle(-47);
  delay(300);
  printf("Shoot the top flag!\n");
  runIndexer(110);
  delay(200);
  runIntake(-120);
  delay(150);
  runIndexer(0); //Starting here
  }
  else{
    runIntake(0);
    turnAngle(-51);
    delay(300);
    printf("Shoot the top flag!\n");
    runIndexer(110);
    delay(200);
    runIntake(-120);
    runIndexer(0); //Starting here
  }
}

void placeSecondCap(){
  if(autonBlue){
    driveStraight(-15.0);
    runIntake(0);
    turnAngle(-135);
    driveStraight(-26.5);
    desiredLiftTicks = 2600;
    delay(100);
    delay(100);
    delay(100);
    delay(200);

    driveStraight(26.5);
    turnAngle(-130);
    driveStraight(17);
    desiredLiftTicks = 760;
    driveStraight(5);
    delay(200);
    driveStraight(-14);
    desiredLiftTicks = 4000;
    turnAngle(-120);
    driveStraight(17);
  }
  else{
    driveStraight(-15.0);
    runIntake(0);
    turnAngle(-141);
    driveStraight(-26.5);
    desiredLiftTicks = 2600;
    delay(100);
    delay(100);
    delay(100);
    delay(200);

    driveStraight(26.5);
    turnAngle(-130);
    driveStraight(17);
    desiredLiftTicks = 760;
    driveStraight(5);
    delay(200);
    driveStraight(-14);
    desiredLiftTicks = 4000;
    turnAngle(-120);
    driveStraight(15);
}
}

void farPlatform(){
  printf("get on the platform!\n");
  driveStraight(38);

}
