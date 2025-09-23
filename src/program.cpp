#include "program.h"
#include "vec2.h"

void nextStep(const double& delta, const vec2& g, Step& last, Step& next) {
  next.vel.x = last.vel.x + g.x * delta;
  next.vel.y = last.vel.y + g.y * delta;

  next.pos.x = last.pos.x + last.vel.x * delta + g.x * delta * delta / 2;
  next.pos.y = last.pos.y + last.vel.y * delta - g.y * delta * delta / 2;
}

bool registerHit(const StepStruct& step, const double& size, const double& eps,
                 const double& left_x, const double& right_x, const double& elevation) {
  if(distance(step.pos, vec2(left_x, elevation)) <= size + eps ||
     distance(step.pos, vec2(right_x, elevation)) <= size + eps)
    return true;
  return false;
}
