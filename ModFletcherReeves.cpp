#include "ModFletcherReeves.h"
#include "Fibonacce.h"
#include "Matrix.h"
#include <iostream>
#include <string>
using namespace std;

ModFletcherReeves::ModFletcherReeves(const Vec & x0_, double gradEps_, double innerEps_, BarrieredFunction & f_) : f(f_)
{
  x0 = x0_;
  gradEps = gradEps_;
  innerEps = innerEps_;
}

Vec ModFletcherReeves::Solve()
{
  Vec vXk(x0);
  Vec vGrad = f.getGrad(vXk);
  StepFunction stepF(f);
  Fibonacce fibb(0.0, 1000, innerEps, stepF);

  while (vGrad.Norm() > gradEps)
  {
    vGrad = f.getGrad(vXk);
    Vec vSk = -1.0 * vGrad;
    double alphaK;
    double betaK = 0;
    Vec lastGrad(DIM);

    bool firstStep = true;

    for (int i = 0; i < DIM; ++i)
    {
#if defined(LOG_GRAD_NORM) ||  defined(LOG_XK_VEC) || defined(LOG_ALPHA) || defined(LOG_ORHTOG) || defined(LOG_BETA) || defined(LOG_SK)
      cout << "----------------------------" << endl;
      cout << "Step no: " << iterCnt + 1 << endl;
#endif // LOG_GRAD_NORM || 

#ifdef LOG_GRAD_NORM
      cout << "Gradient norm: " << vGrad.Norm() << endl;
#endif // LOG_GRAD_NORM

#ifdef LOG_XK_VEC
      vXk.Print("Current Xk:");
#endif // LOG_XK_VEC

      if (!firstStep)
      {
        betaK = vGrad * f.getHess(vXk) * vSk / (vSk * f.getHess(vXk) * vSk);
        vSk = betaK * vSk - vGrad;
      }
      firstStep = false;
#ifdef LOG_BETA
      cout << "Beta: " << betaK << endl;
#endif // LOG_BETA
#ifdef LOG_SK
      vSk.Print("Sk Vector:");
#endif // LOG_SK


      stepF.SetStartVec(vXk, vSk);
      alphaK = fibb.Solve();
      //alphaK = -1.0 * vGrad * vSk / (vSk * f.getHess(vXk) * vSk);

#ifdef LOG_ALPHA
      cout << "Alpha: " << alphaK << endl;
      cout << "Target Alpha: " << -1.0 * vGrad * vSk / (vSk * f.getHess(vXk) * vSk) << endl;
#endif // LOG_ALPHA


      vXk = vXk + alphaK * vSk;

      lastGrad = vGrad *(1.0 / vGrad.Norm());
      vGrad = f.getGrad(vXk);
#ifdef LOG_ORTHOG
      cout << "Orthogonality: " << lastGrad * vGrad / vGrad.Norm() << endl;
#endif // LOG_ORTHOG
      iterCnt++;
    }
    cout << " Ended Step no: " << iterCnt;
    vXk.Print(" Transitional vXk:");

  }

#ifdef LOG_GRAD_NORM
  cout << "Final Gradient norm: " << vGrad.Norm() << endl;
#endif // LOG_GRAD_NORM
  return vXk;
}

void ModFletcherReeves::SetVX0(const Vec & v)
{
  x0 = v;
}

int ModFletcherReeves::GetIterCnt() const
{
  return iterCnt;
}
