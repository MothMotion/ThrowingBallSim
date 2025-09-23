#ifndef PROGRAM_H
#define PROGRAM_H
//#pragma once
#include "vec2.h"


typedef struct StepStruct {
  vec2 pos;
  vec2 vel;

  StepStruct(const double& x, const double& y,
       const double& vx, const double& vy) : pos(x,y), vel(vx,vy) {}
  StepStruct() : pos(), vel() {}
} Step;

void nextStep(const double& delta, const vec2& gravity,
              StepStruct& last_step, StepStruct& write_to_next_step);
bool registerHit(const StepStruct& cur_step, const double& size, const double& epsilon,
                 const double& left_x, const double& right_x, const double& elevation);


#endif // !PROGRAM_H
