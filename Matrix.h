#pragma once
#include "Vec.h"
typedef double mT;


class Matrix
{
private:
  int row = 0, col = 0;
public:
  mT ** data;

  Matrix();
  Matrix(const Matrix& m);
  Matrix(int row_, int col_);
  ~Matrix();
  Matrix& operator=(const Matrix& m);

  void Print(const char * s) const;

  mT* operator[](size_t ind);
  const mT*  operator[](size_t ind) const;

  int getRowCnt() const
  {
    return row;
  }
  int getColCnt()const
  {
    return col;
  }

};

Matrix operator + (const Matrix &m1, const Matrix &m2);
Matrix operator-(const Matrix & m1, const Matrix & m2);
Matrix operator * (const Matrix &m1, mT a);
Matrix operator * (mT a, const Matrix &m1);
Vec operator * (const Matrix &m, const Vec & v);
Vec operator * ( const Vec & v, const Matrix &m);
