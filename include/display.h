#ifndef DISPLAY_H
#define DISPLAY_H

#include "program.h"

#include <raylib.h>

void drawStep(const int& screen_width, const int& screen_height, const double& x, const double& y,
              const double& size, const double& left_x, const double& right_x, const double& elevation,
              const double& ring_width, const double& ring_height, const Color& ball_col, const Color& ring_col, const Color& in_ring_col);

#endif // !DISPLAY_H
