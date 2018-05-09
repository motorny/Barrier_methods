#pragma once
#include "Function.h"

//#define LOG_XK_VEC
//#define LOG_GRAD_NORM
#define LOG_ALPHA
//#define LOG_BETA
//#define LOG_SK
//#define LOG_ORTHOG
//#define LOG_TRANSITIONAL_XK

class ModFletcherReeves
{
protected:
  Function &f;
  double gradEps;
  double innerEps;
  Vec x0;
  int iterCnt = 0;
public:
  ModFletcherReeves(const Vec &x0_, double gradEps_, double innerEps_, Function &f_);
  Vec Solve();
  int GetIterCnt() const;
};

