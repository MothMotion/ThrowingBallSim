#include "display.h"
#include <raylib.h>

void drawStep(const int& scrW, const int& scrH, const double& x, const double& y, const double& size, const double& left_x,
         const double& right_x, const double& elevation, const double& ring_width,
         const double& ring_height, const Color& ball_col, const Color& ring_col, const Color& in_ring_col) {
  DrawRectangle(left_x, scrH - elevation - ring_height, right_x-left_x, ring_height*2, in_ring_col);
  DrawCircle(x, scrH - y, size, ball_col);
  DrawRectangle(left_x - ring_width/2, scrH - elevation - ring_height/2, ring_width, ring_height, ring_col);
  DrawRectangle(right_x - ring_width/2, scrH - elevation - ring_height/2, ring_width, ring_height, ring_col);
}
