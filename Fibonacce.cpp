#include "Fibonacce.h"
#include <iostream>
  
using namespace std;
Fibonacce::Fibonacce(double a_, double b_, double eps_, StepFunction &f_) : f(f_)
{
  aSt = a_;
  bSt = b_;
  eps = eps_;
}
int Fibonacce::Fib_n(int n)
{
  int x = 1;
  int y = 1;
  for (int i = 1; i < n; i++)
  {
    x += y;
    y = x - y;
  }
  return x;
}
double Fibonacce::Solve() {
  double a = aSt;
  double b = bSt;

  double ValToN = (fabs(a - b)) / eps;
  int N = 0;
  while (ValToN >= Fib_n(N))
    N++;
  
  double lambda = a + (b - a) * (double)Fib_n(N - 1) / (double)Fib_n(N + 1);
  double mu = a + (b - a) * (double)Fib_n(N) / (double)Fib_n(N + 1);
  f.ResetRequestCnt();
  double y1 = f.getVal(lambda);
  double y2 = f.getVal(mu);
  int k = 1;
  for (;;) {
    double length1 = (b - a);
    if (y1 > y2)
    {
      a = lambda;
      lambda = mu;
      mu = a + (b - a) * (double)Fib_n(N - k) / (double)Fib_n(N - k + 1);
      if (k == N - 1)
      {
        break;
      }
      y1 = y2;
      y2 = f.getVal(mu);
    }
    else
    {
      b = mu;
      mu = lambda;
      lambda = a + (b - a) * (double)Fib_n(N - k - 1) / (double)Fib_n(N - k + 1);
      if (k == N - 1)
      {
        break;
      }
      y2 = y1;
      y1 = f.getVal(lambda);
    }
    k++;
  }
  /*using namespace std;
  cout << "Interval: ";
  cout << a;
  cout << "; ";
  cout << b;
  cout << "\n";
  cout << "Mu :"; 
  cout << mu;
  cout << " Lambda: ";
  cout << lambda;
  cout << "\n";*/
  mu = lambda + EPS;  
  y1 = f.getVal(lambda);
  y2 = f.getVal(mu);
  if (y1 < y2){
    b = mu;
  }
  else {
    a = lambda;
  }
  return (a + b) / 2.0;

}

