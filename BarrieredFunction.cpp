#include <iostream>

#include "BarrieredFunction.h"

using namespace std;

double BarrieredFunction::getVal(const Vec & v)
{
  if (size() == 0 || targetF == nullptr)
  {
    cout << "Error! Functions list is empty or target Function not defined!" << endl;
    return 0.0;
  }
  double res = targetF->getVal(v);

  for (auto f : (*this))
  {
    res += (-barrierKoeff) / f->getVal(v);
  }
  return res;
}

Vec BarrieredFunction::getGrad(const Vec & v)
{
  if (size() == 0 || targetF == nullptr)
  {
    cout << "Error! Functions list is empty or target Function not defined!" << endl;
    return Vec();
  }
  Vec res = targetF->getGrad(v);

  for (auto f : (*this))
  {
    res = res + barrierKoeff / (f->getVal(v) * f->getVal(v)) * f->getGrad(v);
  }
  return res;
}

double BarrieredFunction::getBarrierVal(const Vec & v)
{
  if (size() == 0)
  {
    cout << "Error! Functions list is empty!" << endl;
    return 0.0;
  }
  double res = 0.0;

  for (auto f : (*this))
  {
    res += barrierKoeff / f->getVal(v);
  }
  return res;
}

bool BarrieredFunction::CrossedBarrier(const Vec & v)
{
  if (size() == 0)
  {
    cout << "Error! Functions list is empty!" << endl;
    return 0.0;
  }
  for (auto f : (*this))
  {
    if (f->getVal(v) > 0)
      return true;
  }
  return false;
}

Matrix BarrieredFunction::getHess(const Vec & v)
{
  return Matrix();
}
