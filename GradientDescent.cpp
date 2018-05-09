#include "GradientDescent.h"
#include "Fibonacce.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

GradientDescent::GradientDescent(Vec & x0_, double gradEps_, double innerEps_, Function & f_) : f(f_), x0(x0_)
{
  gradEps = gradEps_;
  innerEps = innerEps_;
}

void GradientDescent::SetVX0(const Vec & v_)
{
  x0 = v_;
}

Vec GradientDescent::Solve()
{
  Vec xK(x0);
  Vec vGrad = f.getGrad(xK);
  double alfa;
  Vec lastDir(DIM);

  Matrix mA(DIM, DIM);
  mA[0][0] = 1.0;
  //mA[0][0] = 0.5; // Uncomment to optimize current task (founded for current task only)
  mA[1][1] = 1.0;
  //mA[2][2] = 1.0;
  StepFunction stF(f);
  Fibonacce fibb(0.0, 1.0, innerEps, stF);

  while (vGrad.Norm() > gradEps)
  {
#if defined(LOG_GRAD_NORM) ||  defined(LOG_XK_VEC) || defined(LOG_ALPHA) || defined(LOG_ORTHOG)
    cout << "----------------------------" << endl;
    cout << "Step no: " << iterCnt + 1 << endl;
#endif // LOG_GRAD_NORM || 



#ifdef LOG_GRAD_NORM
    cout << "Gradient norm: " << vGrad.Norm() << endl;
#endif // LOG_GRAD_NORM

#ifdef LOG_XK_VEC
    xK.Print("Current Xk:");
#endif // LOG_XK_VEC

    stF.SetStartVec(xK, mA);
    alfa = fibb.Solve();
#ifdef LOG_ALPHA
    cout << "Alfa: " << alfa << endl;
#endif // LOG_ALPHA

    vGrad.Print("Grad:");


    xK = xK - alfa * mA *  vGrad;
    lastDir = vGrad * (1 / vGrad.Norm());
    vGrad = f.getGrad(xK);
#ifdef LOG_ORTHOG
    cout << " ORTOG: " << lastDir * vGrad / vGrad.Norm() << endl;
#endif // LOG_ORTHOG

    iterCnt++;
  }
  return xK;
}
