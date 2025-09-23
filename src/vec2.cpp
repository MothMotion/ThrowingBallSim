#include "vec2.h"
#include <cmath>

double distance(const vec2& a, const vec2& b) {
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
