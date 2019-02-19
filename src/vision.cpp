#include "vars.h"
//All units are in mm
double focal_length = 2.8;
int image_width = VISION_FOV_WIDTH;
int image_height = VISION_FOV_HEIGHT;
//Check the values below
double sensor_height = 2.430;
double sensor_width = 3.888;
double sensor_constant = .7836;
int real_width = 189;
int real_height = 150;

double distanceToSig(int size, int sigNum){
  vision_object_s_t rtn = vis.get_by_sig(size, sigNum);
  int object_width = rtn.width;//156px at 300mm
  double distance = (sensor_constant) * (real_width * image_width) / (object_width);
  return distance;
}

void visTest(){
  vision_object_s_t rtn = vis.get_by_sig(0, 1);
  lcd::print(1, "left Coord: %d", rtn.left_coord);
  lcd::print(2, "top Coord: %d", rtn.top_coord);
  lcd::print(3, "width: %d", rtn.width);
  lcd::print(4, "height: %d", rtn.height);
  int width  = 189;
  double distance = distanceToSig(0,1);
  lcd::print(5, "dist: %f ", distance);
}
