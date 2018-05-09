#pragma once
#include "BarrieredFunction.h"
#include "Grad.h"


//#define LOG_XK_VEC
//#define LOG_GRAD_NORM

class PermanentStep
{
private:
  BarrieredFunction &f;
  double gradEps;
  double alfa;
  Vec x0;
public:
  PermanentStep(Vec &x0_, double gradEps_, double alfa_, BarrieredFunction &f_);
  Vec Solve();
  void SetVX0(const Vec&v);
  int iterCnt = 0;
};

