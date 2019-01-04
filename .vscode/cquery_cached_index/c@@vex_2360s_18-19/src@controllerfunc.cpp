#include "../vars.h"
//-----I---------Initialize Controller---------------
Controller master (E_CONTROLLER_MASTER);
Controller partner (E_CONTROLLER_PARTNER);


//------------Map Controller Input to Motors---------
int flywheelCtl;
int indexerCtl;
int intakeCtl;
int tankSpeedCtl;
void flywheelControl(){
	flywheelCtl = (partner.get_digital(E_CONTROLLER_DIGITAL_X)) +
								(partner.get_digital(E_CONTROLLER_DIGITAL_A) << 1) +
								(partner.get_digital(E_CONTROLLER_DIGITAL_B) << 2);

	switch(flywheelCtl){
		case 1: //BtnX
      runFlywheel(127);
			break;
		case 2: //BtnA
      runFlywheel(90);
			break;
		case 4: //BtnB
			runFlywheel(0);
			break;
	}
}

void intakeControl(){
	intakeCtl = (master.get_digital(E_CONTROLLER_DIGITAL_R1)) +
							(master.get_digital(E_CONTROLLER_DIGITAL_R2) << 1);

	switch(intakeCtl){
		case 1: //BtnL1
			runIntake(-127);
			break;
		case 2: //BtnL2
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
			runIndexer(100);
			break;
		case 2: //BtnR2
			runIndexer(-100);
			break;

		default:
			runIndexer(0);
	}
}

void tankSpeedControl(){
  tankSpeedCtl = (partner.get_digital(E_CONTROLLER_DIGITAL_UP)) +
								(partner.get_digital(E_CONTROLLER_DIGITAL_LEFT) << 1) +
								(partner.get_digital(E_CONTROLLER_DIGITAL_DOWN) << 2);

	switch(tankSpeedCtl){
		case 1: //BtnUP-Partner
      tankKp = 1.1;
			break;
		case 2: //BtnLEFT-Partner
      tankKp = 1.5;
			break;
		case 4: //BtnDOWN-Partner
			tankKp = 2.0;
			break;
	}
}
