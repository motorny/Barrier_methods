#include "Vec.h"
using namespace std;
#define EPS 1e-6
#include <iostream>
#include <iomanip>

Vec::Vec()
{
}
Vec::Vec(int size_)
{
  data = new mT[size_];
  for (int i = 0; i < size_; ++i) {
    data[i] = 0.0;
  }
  size = size_;
}

Vec::Vec(const Vec & v)
{
  size = v.getSize();
  data = new mT[size];
  for (int i = 0; i < size; ++i)
    data[i] = v[i];
}

Vec & Vec::operator=(const Vec & v)
{
  if (size != v.getSize())
  {
    delete[] data;
    size = v.getSize();
    data = new mT[size];
  }

  for (int i = 0; i < size; ++i)
    data[i] = v[i];
  return (*this);
}

Vec::~Vec()
{
  delete[] data;
}




double Vec::Norm()
{
  return sqrt((*this)*(*this));
}


void Vec::SetZeros()
{
  for (int i = 0; i < size; ++i)
    data[i] = 0.0;
}

void Vec::Print(const char * s) const
{
  cout << s << endl;
  for (int iRow = 0; iRow < size; iRow++)
  {
    cout << setw(5) << data[iRow] << endl;
  }
}


mT & Vec::operator[](size_t ind)
{
  return data[ind];
}

mT Vec::operator[](size_t ind) const
{
  return data[ind];
}

Vec operator+(const Vec & v1, const Vec & v2)
{
  if (v1.getSize() != v2.getSize())
  {
    cout << "VEC DIMENSION ERROR" << endl;
    return Vec();
  }

  Vec res(v1.getSize());
  for (int i = 0; i < v1.getSize(); ++i)
    res[i] = v1[i] + v2[i];

  return res;
}

Vec operator-(const Vec & v1, const Vec & v2)
{
  if (v1.getSize() != v2.getSize())
  {
    cout << "VEC DIMENSION ERROR" << endl;
    return Vec();
  }

  Vec res(v1.getSize());
  for (int i = 0; i < v1.getSize(); ++i)
    res[i] = v1[i] - v2[i];

  return res;
}
Vec operator*(const Vec & v1, mT a)
{
  Vec res(v1.getSize());
  for (int i = 0; i < v1.getSize(); ++i)
    res[i] = v1[i] * a;
  return res;
}

Vec operator*(mT a, const Vec & v1)
{
  Vec res(v1.getSize());
  for (int i = 0; i < v1.getSize(); ++i)
    res[i] = v1[i] * a;
  return res;
}

mT operator*(const Vec & v1, const Vec & v2)
{
  mT sum = 0.0;
  if (v1.getSize() != v2.getSize())
  {
    cout << "VEC DIMENSION ERROR" << endl;
    return 0.0;
  }

  for (int i = 0; i < v1.getSize(); ++i)
    sum += v1[i] * v2[i];
  return sum;
}
