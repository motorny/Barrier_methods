#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>

#include "BarrierSolver.h"

#include "TargetFunction.h"
#include "Constr1.h"
#include "Constr2.h"
#include "Constr3.h"

using namespace std;


/*
 * INFO:
 * Current task dimension: 3
 * MODIFY gloabal defines!!!
 */


int main(void)
{
  Vec trueRes(DIM);
  trueRes[0] = 0.57735026918962576450914878050196;
  trueRes[1] = 0.57735026918962576450914878050196;
  trueRes[2] = 0.57735026918962576450914878050196;

  Vec x0(DIM);
  x0[0] = 0.65;
  x0[1] = 0.65;
  double barrierEps = 1e-4;
  double gradEps = 1e-4;
  double innerEps = 1e-4;

  BarrieredFunction bf;
  TargetFunction tf;
  Constr1 c1;
  Constr2 c2;
  Constr3 c3;

  bf.targetF = &tf;
  bf.push_back(&c1);
  bf.push_back(&c2);
  bf.push_back(&c3);

  cout << "Barrier method using Gradient Descent:" << endl;
  BarrierSolver bs(x0,barrierEps, gradEps, innerEps, bf);
  Vec res = bs.Solve();
  Vec err = res - trueRes;
  cout << "--------------------------------------------" << endl;
  cout << "x: " << fixed << setprecision(10) << res[0] << endl;
  cout << "y: " << fixed << setprecision(10) << res[1] << endl;
  cout << "z: " << fixed << setprecision(10) << res[2] << endl;
  cout << "Steps count: " << bs.iterCnt << endl;
  cout << "Error: " << err.Norm() << endl;
  cout << endl << endl;

  return 0;
}