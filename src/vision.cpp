#include "vars.h"
void visTest(){
  vision_object_s_t rtn = vis.get_by_sig(0, 1);
  lcd::print(1, "left Coord: %d", rtn.left_coord);
  lcd::print(2, "top Coord: %d", rtn.top_coord);
  lcd::print(3, "width: %d", rtn.width);
  lcd::print(4, "height: %d", rtn.height);
  int width  = 152;
  int distance = (width * 260)/rtn.width;
  lcd::print(5, "dist: %d", distance);
}
