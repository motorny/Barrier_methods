#pragma once

#include "BarrieredFunction.h"


#define LOG_XK_VEC
#define LOG_BARRIERVAL
#define LOG_BARRIERKOEF

class BarrierSolver
{
  BarrieredFunction& bf;
  double barierEps;
  double gradEps;
  double innerEps;
  Vec x0;
public:
  BarrierSolver(Vec &x0_, double barierEps_, double gradEps_, double innerEps_, BarrieredFunction& bf_);
  Vec Solve();
  int iterCnt = 0;
};

