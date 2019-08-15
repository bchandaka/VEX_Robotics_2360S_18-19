# VEX_2360S_18-19
Our team had a great time utilizing PROS to program the robot this year. Being able to use the full functionality of C++ allowed us to explore various algorithms for autonomous control and even create a custom motor class for easier debugging and greater control.
### The Robot
![Image of The Robot](https://github.com/bchandaka/VEX_Robotics_2360S_18-19/blob/master/Robot_18-19.JPG)
### Programming Features
  *The code has been nearly fully commented, but here is an overview of some unique features in our code*
- **smartMotor class**
  - all motors are objects of this class in our code
  - contains more variables/functions to better integrate the motor object with the the control algorithms utilized on nearly every motor
    - Holds PID constants
    - Holds current and desired velocity variables for slew control
    - Allows positon sensor values(of any type: potentiometer, encoder, or integrated encoder) to be accessed from the motor object itself rather a separate sensor object
    - includes a function that prints motor data to the lcd for easier debugging.
- **Motor Slew Rate Control**
  - A control algorithm that limits how fast a motor changes its speed to prevent jerky motor movement
  - Allows only small changes in motor speed to incrementally reach the desired velocity from the motor's current velocity rather than immediately trying to reach the new desired velocity
  - Creates smoother motor motion without adding noticeable lag between setting a new desired velocity and reaching it
- **PID(Proportional-Integral-Derivative) Control**
  - An advanced control algorithm used for accurate, autonomous motion
  - Causes the motor to gradually slow down as it gets closer to its target position, prevent overshoot and ensuring accuracy
  - Primarily used on the chassis to accurately move during the autonomous period
*The src folder contains all the main programming files*
