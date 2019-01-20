#include "../vars.h"

//LCD Advanced Functions
const char RIGHT_ARROW = 199;
const char LEFT_ARROW = 200;


#ifndef NUM_AUTON_OPTIONS
	#define NUM_AUTON_OPTIONS 4
#endif

bool autonBlue = false;
int autonVer = 1;


void displayStatus() {
    std::string line2 = autonBlue ? "BLUE" : "RED";
    std::string line3 = std::to_string(autonVer);

    pros::lcd::set_text(0, "Side (mid btn):   " + line2);
    pros::lcd::set_text(1, "AutonNum (right btn):" + line3);
		switch(autonVer){
			case 1:
				pros::lcd::set_text(3, "Near Side + Platform" );
				break;
			case 2:
				pros::lcd::set_text(3, "Near Side + No Platform" );
				break;
			case 3:
				pros::lcd::set_text(3, "Far Side + Platform" );
				break;
			case 4:
				pros::lcd::set_text(3, "Far Side + No Platform" );
				break;

		}
}

void on_btnL() {
    displayStatus();
}

void on_btnM() {
    autonBlue = !autonBlue;
    displayStatus();
}

void on_btnR() {
    autonVer += 1;
    if (autonVer > NUM_AUTON_OPTIONS){
      autonVer = 1;
    }
    displayStatus();
}
