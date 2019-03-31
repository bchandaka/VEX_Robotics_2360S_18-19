#include "vars.h"

void getBall(){
  intake.run(-120);
  flywheel.run(126);
  driveStraight(43.0);
  printf("moving backward!\n");
  driveStraight(-31.0);
}

void shootHighFlags(){
  //face the flags
  turnAngle(-92);
  driveStraight(6);
  intake.run(0);
  delay(100);
  printf("Shoot the top flag!\n");
  indexer.run(126);
  delay(150);
  indexer.run(0);
  printf("Move closer to shoot middle flag!\n");
  flywheel.run(127);
  intake.run(-120);
  driveStraight(21);
  delay(100);
  intake.run(0);
  printf("Shoot the middle flag!\n");
  indexer.run(120);
  delay(400);
  indexer.run(0);
  flywheel.run(0);
}
void shootLowFlag(){
  if(autonBlue){
    printf("Ram the bottom flag!\n");
    turnAngle(-15);
    driveStraight(16);
    printf("back out of flag and come back!\n");
    driveStraight(-16);
    turnAngle(15);
    intake.run(80);
  }
  else{
    printf("Ram the bottom flag!\n");
    turnAngle(-15);
    driveStraight(16);
    printf("back out of flag and come back!\n");
    driveStraight(-16);
    turnAngle(15);
    intake.run(80);
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
    intake.run(0);
    turnAngle(-45);
    intake.run(0);
    driveStraight(30);
    turnAngle(-60);
  }
  else{
    driveStraight(-3);
    intake.run(0);
    turnAngle(-45);
    intake.run(0);
    driveStraight(30);
    turnAngle(-60);
  }
}
void nearPlatform(){
  printf("face platform!\n");
  intake.run(-120);
  driveStraight(-47);
  turnAngle(90);

  printf("get on the red platform!\n");
  driveStraight(57);
}

void getFarBall(){
  intake.run(-120);
  flywheel.run(127);
  driveStraight(43.0);
  printf("moving backward!\n");
  //driveStraight(-32.0);
}
void shootMiddleFlags(){
  intake.run(0);
  turnAngle(-54);
  delay(300);
  printf("Shoot the top flag!\n");
  indexer.run(110);
  delay(200);
  indexer.run(0); //Starting here
  intake.run(-120);
  delay(200);
  printf("Move back to shoot middle flag!\n");
  driveStraight(-6);

  intake.run(0);
  printf("Shoot the middle flag!\n");
  indexer.run(120);
  delay(500);
  indexer.run(0);
  flywheel.run(0);
  driveStraight(6);
}
void shootHighMiddleFlag(){
  if(autonBlue){
  intake.run(0);
  turnAngle(-47);
  delay(300);
  printf("Shoot the top flag!\n");
  indexer.run(110);
  delay(200);
  intake.run(-120);
  delay(150);
  indexer.run(0); //Starting here
  }
  else{
    intake.run(0);
    turnAngle(-51);
    delay(300);
    printf("Shoot the top flag!\n");
    indexer.run(110);
    delay(200);
    intake.run(-120);
    indexer.run(0); //Starting here
  }
}

void placeSecondCap(){
  if(autonBlue){
    driveStraight(-15.0);
    intake.run(0);
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
    intake.run(0);
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
