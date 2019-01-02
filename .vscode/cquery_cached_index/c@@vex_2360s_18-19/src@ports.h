#ifndef PORTS_H
#define PORTS_H
#include "main.h"
class smartMotor{
  int port;
  int slewRate;
  int reqVel;
  int currVel;
  Motor mtr;
  public:
    smartMotor(int port, motor_gearset_e_t gearset, bool reversed, motor_encoder_units_e_t encoderUnits);
    void runVel(int vel);
    void runVelImmediate(int vel);
    void setCurrVel(int vel);
    void setSlew(std::string slew);
    int getPort();
    int getVel();
    motor_gearset_e_t getGears();
    motor_encoder_units_e_t getEncoderUnits();
    void kill();
};

#endif
