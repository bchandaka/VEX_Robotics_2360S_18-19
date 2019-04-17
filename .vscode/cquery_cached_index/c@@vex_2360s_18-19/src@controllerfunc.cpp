#include "vars.h"
//-----I---------Initialize Controller---------------
Controller master (E_CONTROLLER_MASTER);
Controller partner (E_CONTROLLER_PARTNER);

//-----------------Tank Drive Function--------------
#define JOY_THRESHOLD	15
double tankKp = 1.2;
int    ctl_l;
int    ctl_r;
int    drive_l;
int    drive_r;
void tankDrive(){
	// Get tank drive vertical joystick control
	ctl_l = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/tankKp;
	ctl_r = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/tankKp;
	// Ignore joystick near center to prevent powering motors when the joystick doesn't properly center to zero
	drive_l = (abs(ctl_l) <= JOY_THRESHOLD) ? 0:ctl_l;
	drive_r = (abs(ctl_r) <= JOY_THRESHOLD) ? 0:ctl_r;
  //Send it!
	leftDrive.run(drive_l);
	rightDrive.run(drive_r);
}

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
			flywheel.run(127);
			break;
		case 2: //BtnA
			flywheel.run(127);
			break;
		case 4: //BtnB
			flywheel.run(0);
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
	if(bottomLimit.get_value() && false){

	}
	else{
		switch(intakeCtl){
			case 1 : //BtnR1
				intake.run(-127);
				break;
			case 2: //BtnR2
				intake.run(60);
				break;
			case 4: //BtnL1 Partner
				intake.run(-127);
				break;
			case 5: //If both buttons are pressed
				intake.run(-127);
				break;
			case 8: //BtnL2 Partner
				intake.run(60);
				break;
			case 10: //If both buttons are pressed
				intake.run(60);
				break;
			default:
					intake.run(0);
		}
	}
}

void indexerControl(){
	indexerCtl = (master.get_digital(E_CONTROLLER_DIGITAL_L1)) +
							 (master.get_digital(E_CONTROLLER_DIGITAL_L2) << 1);

		switch(indexerCtl){
			case 1: //BtnR1
				indexer.run(127);
				break;
			case 2: //BtnR2
				indexer.run(-127);
				break;
			default:
				indexer.run(0);

	}
}

const int NUM_HEIGHTS = 3;
const int height1 = 300;
const int height2 = 1300;
const int height3 = 3400;


const int heights[NUM_HEIGHTS] = {height1, height2, height3};
int goalHeight = 0;

void liftControl(){
	liftCtl = (partner.get_digital(E_CONTROLLER_DIGITAL_L1)) +
							 (partner.get_digital(E_CONTROLLER_DIGITAL_L2) << 1);
	if(partner.get_digital_new_press(E_CONTROLLER_DIGITAL_RIGHT)){
		lift.setIsPID(!(lift.isPID()));
	}

	if (lift.isPID())
	{
		liftCtl = (partner.get_digital_new_press(E_CONTROLLER_DIGITAL_L1)) +
								 (partner.get_digital_new_press(E_CONTROLLER_DIGITAL_L2) << 1);
		if (liftCtl==1 && goalHeight < NUM_HEIGHTS - 1) {
      // If the goal height is not at maximum and the up button is pressed, increase the setpoint
      goalHeight++;
      lift.setTarget(heights[goalHeight]);
    }
		else if (liftCtl==2 && goalHeight > 0) {
      goalHeight--;
			lift.setTarget(heights[goalHeight]);
    }
	}
	else{
		switch(liftCtl){
			case 1: //BtnL1
				lift.run(-127);
				break;
			case 2: //BtnL2
				lift.run(127);
				break;
			default:
				lift.run(0);
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
