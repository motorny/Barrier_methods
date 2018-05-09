#include "BarrierSolver.h"

#include "PermanentStep.h"
#include <math.h>
#include <iostream>
using namespace std;



BarrierSolver::BarrierSolver(Vec & x0_, double barierEps_, double gradEps_, double innerEps_, BarrieredFunction & bf_): bf(bf_), x0(x0_)
{
  barierEps = barierEps_;
  gradEps = gradEps_;
  innerEps = innerEps_;
}

Vec BarrierSolver::Solve()
{
  Vec vXk(x0);
  PermanentStep ps(vXk, gradEps, innerEps, bf);

  
  bf.barrierKoeff = 1.0;
  double barrierLambda = 0.5;

  while (fabs(bf.getBarrierVal(vXk)) > barierEps)
  {
#if defined(LOG_XK_VEC) || defined(LOG_BARRIERVAL)  || defined(LOG_BARRIERKOEF)
    cout << "****************************" << endl;
    cout << "Barrier method Step no: " << iterCnt + 1 << endl;
#endif // LOG_GRAD_NORM || 

    ps.SetVX0(vXk);
    vXk = ps.Solve();
    bf.barrierKoeff *= barrierLambda;

#ifdef LOG_XK_VEC
    vXk.Print("Current Xk:");
#endif // LOG_XK_VEC

#ifdef LOG_BARRIERKOEF
    cout << "Barrie rKoeff: " << bf.barrierKoeff << endl;
#endif // LOG_BARRIERKOEF


#ifdef LOG_BARRIERVAL
    cout << "Barrier Val: " << fabs(bf.getBarrierVal(vXk)) << endl;
#endif // LOG_ALPHA


    iterCnt++;
  }

  return vXk;
}
