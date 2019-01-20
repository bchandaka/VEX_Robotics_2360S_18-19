#include "../vars.h"

void auton3(){
delay(1500);
int start = millis();

printf("auton3\n");
intake.move(-120);
driveStraight(43.0);
printf("%d\n", motorReq[6]);
printf("moving backward\n");
//driveStraight(-34.0);
driveLeft1.move(-40); //- (gyroError *gyroKp));
driveLeft2.move(40);
driveRight1.move(-40); //- (gyroError *gyroKp));
driveRight2.move(40);
delay(1000);
driveLeft1.move(0); //- (gyroError *gyroKp));
driveLeft2.move(0);
driveRight1.move(0); //- (gyroError *gyroKp));
driveRight2.move(0);
printf("%d\n",millis()-start);
printf("autonDone\n");
intake.move(0);
}
