#include "StepFunction.h"

StepFunction::StepFunction(Function & f_) : f(f_)
{
}

void StepFunction::SetStartVec(const Vec & v0, const Vec& dir_)
{
  xK = v0;
  dir = dir_;
}
