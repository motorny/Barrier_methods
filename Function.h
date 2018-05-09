#pragma once
#include "Vec.h"

class Function {
public:
  virtual double getVal(const Vec& v) = 0;
  virtual Vec getGrad(const Vec& v) = 0;
};