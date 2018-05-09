#pragma once

#include "Function.h"

class Constr2 : public Function
{
public:
  double getVal(const Vec& v) override
  {
    return v[1] - 0.7;
  }
  Vec getGrad(const Vec& v) override
  {
    Vec res(DIM);
    res[1] = 1.0;
    return res;
  }
};