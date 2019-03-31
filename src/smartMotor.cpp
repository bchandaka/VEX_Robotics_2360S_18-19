#include "smartMotor.h"

//-----Constructors-----
smartMotor::smartMotor( int port,
                        pros::motor_gearset_e_t gearset,
                        bool reversed,
                        sensorType sensor,
                        int sensorPort){
    this->port = port;
    this->reversed = true;
    this->slewRate = 30;
    this->reqVel = 10;
    this->curVel = 0;
    this-> motorPointer = new pros::Motor(port, gearset, reversed, pros::E_MOTOR_ENCODER_COUNTS);
    this-> encoder = integrated;
    this-> kP = 0;
    this-> kI = 0;
    this-> kD = 0;
    this-> encoder = sensor;
    if(encoder==quadrature){
      this-> quadPointer = new pros::ADIEncoder(sensorPort, sensorPort-1, false);
    }
    else if(encoder == potentiometer){
      this-> potPointer = new pros::ADIPotentiometer(sensorPort);
    }
}

//------Getters------
int smartMotor::getPort(){
  return port;
}
int smartMotor::getReqVel(){
  return reqVel;
}
int smartMotor::getCurVel(){
  return curVel;
}
int smartMotor::getSlew(){
  return slewRate;
}
bool smartMotor::getReversed(){
  return reversed;
}
pros::Motor smartMotor::getMtr(){
  return *motorPointer;
}
double smartMotor::getPosition(){
  switch(encoder){
    case integrated:
      return (*motorPointer).get_position();
      break;
    case quadrature:
      return (*quadPointer).get_value();
      break;
    case potentiometer:
      return (*potPointer).get_value();
      break;
  }
}
//------Setters------
void smartMotor::run(int vel){
  reqVel = vel;
  if(slaveMtrPointer){
    (*slaveMtrPointer).run(vel);
  }
}
void smartMotor::setCurVel(int vel){
  curVel = vel;
}
void smartMotor::setSlew(int slew){
  slewRate = slew;
}
void smartMotor::reset(){
  reqVel = 0;
  curVel = 0;
  switch(encoder){
    case integrated:
      (*motorPointer).tare_position();
      break;
    case quadrature:
      (*quadPointer).reset();
      break;
    case potentiometer:
      break;
  }
  if(slaveMtrPointer){
    slaveMtrPointer->reset();
  }
}
void smartMotor::addSlave(smartMotor* slaveMtr){
  slaveMtrPointer = slaveMtr;
}

//PID
void smartMotor::setPIDConst(double kP, double kI, double kD){
    this->kP = kP;
    this->kI = kI;
    this->kD = kD;
}

double smartMotor::calcPID(double error, double integral, double derivative){
    return error* (kP) + integral * (kI) + derivative * (kD);
}
void smartMotor::debug(int lcdLine){
  pros::lcd::initialize();
  pros::lcd::print(lcdLine,"Port:%d Pwr: %d, Pos:%f", port, curVel, getPosition());
}
