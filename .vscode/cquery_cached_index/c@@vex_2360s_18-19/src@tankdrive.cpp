#include "../vars.h"
//-----------------Tank Drive Task--------------
#define JOY_THRESHOLD	15
double tankKp = 1.4;
void tankDrive(void* params){
	int    ctl_l;
	int    ctl_r;
	int    drive_l;
	int    drive_r;
	while(true){
		// Get tank drive vertical joystick control
		ctl_l = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)/tankKp;
		ctl_r = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y)/tankKp;
		// Ignore joystick near center to prevent powering motors when the joystick doesn't properly center to zero
		drive_l = (abs(ctl_l) <= JOY_THRESHOLD) ? 0:ctl_l;
		drive_r = (abs(ctl_r) <= JOY_THRESHOLD) ? 0:ctl_r;
    //Send it!
		runDriveLeft(drive_l);
		runDriveRight(drive_r);

		delay(20);
	}
}
