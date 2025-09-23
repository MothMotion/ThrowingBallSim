#ifndef VEC2_H
#define VEC2_H

typedef struct Vec2Struct {
  double x,y;

  Vec2Struct(const double& x, const double& y) : x(x), y(y) {}
  Vec2Struct() : x(), y() {}
} vec2;

double distance(const vec2&, const vec2&);

#endif // !VEC2_H
