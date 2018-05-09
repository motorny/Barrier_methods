#include "PermanentStep.h"
#include <iostream>
using namespace std;

PermanentStep::PermanentStep(Vec & x0_, double gradEps_, double alfa_, BarrieredFunction & f_) : f(f_), x0(x0_)
{
  gradEps = gradEps_;
  alfa = alfa_;
}

Vec PermanentStep::Solve()
{
  Vec xK(x0);
  Vec vGrad = f.getGrad(xK);
  
  double delta = 0.8;
  double alfa0 = 1.0;
  double curAlfa;
  double eps = 0.5;

  while (vGrad.Norm() > gradEps)
  {
    curAlfa = alfa0;
#if defined(LOG_GRAD_NORM) ||  defined(LOG_XK_VEC)
    cout << "----------------------------" << endl;
    cout << "Step no: " << iterCnt + 1 << endl;
#endif // LOG_GRAD_NORM || 

#ifdef LOG_GRAD_NORM
    cout << "Gradient norm: " << vGrad.Norm() << endl;
#endif // LOG_GRAD_NORM

   
#ifdef LOG_XK_VEC
    xK.Print("Current Xk:");
#endif // LOG_XK_VEC
    while (f.getVal(xK - curAlfa*vGrad)- f.getVal(xK) > -eps*curAlfa*(f.getGrad(xK)*f.getGrad(xK))
      || f.CrossedBarrier(xK - curAlfa*vGrad))
    {
      Vec xT = xK - curAlfa*vGrad;
      //xT.Print("Temp Vec:");
      curAlfa *= delta;
    }

    xK = xK - curAlfa*vGrad;
    vGrad = f.getGrad(xK);
    iterCnt++;
  }
  return xK;
}

void PermanentStep::SetVX0(const Vec & v)
{
  x0 = v;
}
