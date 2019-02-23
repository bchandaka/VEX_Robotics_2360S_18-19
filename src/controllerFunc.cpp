#include "vars.h"
//-----I---------Initialize Controller---------------
Controller master (E_CONTROLLER_MASTER);
Controller partner (E_CONTROLLER_PARTNER);


//------------Map Controller Input to Motors---------
int flywheelCtl; //Variable to control flywheel switch statement
int indexerCtl; //Variable to control indexer switch statement
int intakeCtl; //Variable to control intake switch statement
int liftCtl; //Variable to control lift switch statement

int tankSpeedCtl; //Variable to control tank switch statement
void flywheelControl(){
	flywheelCtl = (partner.get_digital(E_CONTROLLER_DIGITAL_X)) +
								(partner.get_digital(E_CONTROLLER_DIGITAL_A) << 1) +
								(partner.get_digital(E_CONTROLLER_DIGITAL_B) << 2);

	switch(flywheelCtl){
		case 1: //BtnX
      runFlywheel(127);
			break;
		case 2: //BtnA
      runFlywheel(110);
			break;
		case 4: //BtnB
			runFlywheel(0);
			break;
	}
}

void intakeControl(){
	//Bit shift
	//Shifts the bit over by the desired amount in binary and converts to decimal
 //Use switch statement to get desired output
	intakeCtl = (master.get_digital(E_CONTROLLER_DIGITAL_R1)) +
							(master.get_digital(E_CONTROLLER_DIGITAL_R2) << 1)+
							(partner.get_digital(E_CONTROLLER_DIGITAL_R1) << 2) +
							(partner.get_digital(E_CONTROLLER_DIGITAL_R2) << 3);
	switch(intakeCtl){
		case 1 : //BtnR1
			runIntake(-127);
			break;
		case 2: //BtnR2
			runIntake(127);
			break;
		case 4: //BtnL1 Partner
			runIntake(-127);
			break;
		case 5: //If both buttons are pressed
			runIntake(-127);
			break;
		case 8: //BtnL2 Partner
			runIntake(127);
			break;
		case 10: //If both buttons are pressed
			runIntake(127);
			break;
		default:
			runIntake(0);
	}
}

void indexerControl(){
	indexerCtl = (master.get_digital(E_CONTROLLER_DIGITAL_L1)) +
							 (master.get_digital(E_CONTROLLER_DIGITAL_L2) << 1);

	switch(indexerCtl){
		case 1: //BtnR1
			runIndexer(127);
			break;
		case 2: //BtnR2
			runIndexer(-127);
			break;
		default:
			runIndexer(0);
	}
}

const int NUM_HEIGHTS = 3;
const int height1 = 4000;
const int height2 = 2600;
const int height3 = 760;


const int heights[NUM_HEIGHTS] = {height1, height2, height3};
int goalHeight = 0;
int desiredLiftTicks = heights[0];
bool isLiftPID = true;

void liftControl(){
	liftCtl = (partner.get_digital(E_CONTROLLER_DIGITAL_L1)) +
							 (partner.get_digital(E_CONTROLLER_DIGITAL_L2) << 1);
	if(partner.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)){
		isLiftPID = !isLiftPID;
	}

	if (isLiftPID)
	{
		lcd::print(5, "goalHeight: %d", goalHeight);
		liftCtl = (partner.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) +
								 (partner.get_digital_new_press(E_CONTROLLER_DIGITAL_L2) << 1);
		if (liftCtl==1 && goalHeight < NUM_HEIGHTS - 1) {
      // If the goal height is not at maximum and the up button is pressed, increase the setpoint
      goalHeight++;
      desiredLiftTicks = heights[goalHeight];
    }
		else if (liftCtl==2 && goalHeight > 0) {
      goalHeight--;
      desiredLiftTicks = heights[goalHeight];
    }
	}
	else{
		switch(liftCtl){
			case 1: //BtnL1
				runLift(-127);
				break;
			case 2: //BtnL2
				runLift(127);
				break;
			default:
				runLift(0);
		}
	}
}

void tankSpeedControl(){
  tankSpeedCtl = (partner.get_digital(E_CONTROLLER_DIGITAL_UP)) +
								(partner.get_digital(E_CONTROLLER_DIGITAL_LEFT) << 1) +
								(partner.get_digital(E_CONTROLLER_DIGITAL_DOWN) << 2);

	switch(tankSpeedCtl){
		case 1: //BtnUP-Partner
      tankKp = 1;
			master.rumble((".."));
			break;
		case 2: //BtnLEFT-Partner
      tankKp = 1.2;
			master.rumble(("."));
			break;
		case 4: //BtnDOWN-Partner
			tankKp = 1.7;
			master.rumble(("-"));
			break;
	}
}
