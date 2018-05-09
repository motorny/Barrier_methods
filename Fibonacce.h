#pragma once
#define EPS 1e-10
#include "StepFunction.h"
class Fibonacce {
public:
  Fibonacce(double a_, double b_, double eps_, StepFunction &f_);
  double Solve();

private:
  int Fib_n(int n);
  StepFunction &f;
  double aSt;
  double bSt;
  double eps;
};