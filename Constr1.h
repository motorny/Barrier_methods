#pragma once

#include "Function.h"

class Constr1 : public Function
{
public:
  double getVal(const Vec& v) override
  {
    return v[0] - 0.7;
  }
  Vec getGrad(const Vec& v) override
  {
    Vec res(DIM);
    res[0] = 1.0;
    return res;
  }
};