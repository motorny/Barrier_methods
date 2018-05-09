#pragma once
#include <math.h>
#include "Vec.h"
typedef struct {
  double a;
  double b;
  int fcount;
  int icount;
}intrvl_t;

class Grad {
private:
  int requestCnt = 0;
public:
  int GetRequestCnt()
  {
    return requestCnt;
  }

  void ResetRequestCnt()
  {
    requestCnt = 0;
  }

  Vec getVal(Vec & v)
  {
    requestCnt++;
    Vec res(DIM);
    res[0] = 3.0 + 8.0 * v[0] / sqrt(1 + 2.0 * v[0] * v[0] + v[1] * v[1]);
    res[1] = 1.0 + 4.0 * v[1] / sqrt(1 + 2.0 * v[0] * v[0] + v[1] * v[1]);
    return res;
  }
};

