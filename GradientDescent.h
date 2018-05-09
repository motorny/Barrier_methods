#pragma once
#include "Function.h"
#include "Grad.h"


#define LOG_XK_VEC
#define LOG_GRAD_NORM
#define LOG_ALPHA
#define LOG_ORTHOG

class GradientDescent
{
  Function &f;
  double gradEps;
  double innerEps;
  Vec x0;
public:
  GradientDescent(Vec &x0_, double gradEps_, double innerEps_, Function &f_);
  void SetVX0(const Vec& v_);
  Vec Solve();
  int iterCnt = 0;
};

