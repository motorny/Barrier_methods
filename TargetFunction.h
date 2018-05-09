#pragma once

#include "Function.h"

class TargetFunction : public Function
{
public:
  double getVal(const Vec& v) override
  {
    return (v[0] - 1) * (v[0] - 1) + (v[1] - 1) * (v[1] - 1) +(v[2] - 1) * (v[2] - 1);
  }
  Vec getGrad(const Vec& v) override
  {
    Vec res(DIM);
    res[0] = 2.0 * (v[0] - 1);
    res[1] = 2.0 * (v[1] - 1);
    res[2] = 2.0 * (v[2] - 1);
    return res;
  }
};
