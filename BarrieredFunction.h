#pragma once

#include <list>
#include "Function.h"

typedef double mT;

class BarrieredFunction : public Function , public std::list<Function*>
{
public:
  mT barrierKoeff = 1.0;
  Function * targetF;
  virtual double getVal(const Vec& v) override;
  virtual Vec getGrad(const Vec& v) override;
  double getBarrierVal(const Vec& v);
  bool CrossedBarrier(const Vec& v);
};