#include "../vars.h"

//LCD Advanced Functions
const char RIGHT_ARROW = 199;
const char LEFT_ARROW = 200;


#ifndef NUM_AUTON_OPTIONS
	#define NUM_AUTON_OPTIONS 6
#endif

bool skillsAuton = false;
bool autonBlue = false;
int autonVer = 1;


void displayStatus() {
    std::string line1 = skillsAuton ? "TRUE" : "FALSE";
    std::string line2 = autonBlue ? "BLUE" : "RED";
    std::string line3 = std::to_string(autonVer);

    pros::lcd::set_text(0, "skillsAuton? (left btn): " + line1);
    pros::lcd::set_text(1, "Side (mid btn):   " + line2);
    pros::lcd::set_text(2, "AutonNum (right btn):" + line3);
}

void on_btnL() {
    skillsAuton = !skillsAuton;
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
