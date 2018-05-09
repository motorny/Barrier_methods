#include "Matrix.h"

using namespace std;
#define EPS 1e-6
#include <iostream>
#include <iomanip>
Matrix::Matrix()
{
}
Matrix::Matrix(const Matrix & m)
{
  row = m.getRowCnt();
  col = m.getColCnt();

  data = new mT*[row];
  for (int rI = 0; rI < row; ++rI)
  {
    data[rI] = new mT[col];
    for (int cI = 0; cI < col; ++cI)
      data[rI][cI] = m[rI][cI];
  }
}

Matrix::Matrix(int row_, int col_)
{
  row = row_;
  col = col_;
  data = new mT*[row];
  for (int rI = 0; rI < row; ++rI)
  {
    data[rI] = new mT[col];
    for (int cI = 0; cI < col; ++cI)
      data[rI][cI] = 0.0;
  }
}

Matrix::~Matrix()
{
  for (int rI = 0; rI < row; ++rI)
  {
    delete[] data[rI];
  }
  delete[] data;
}

Matrix & Matrix::operator=(const Matrix & m)
{
  if (row != m.getRowCnt() || col != m.getColCnt())
  {
    // if matrix has differtn size

    for (int rI = 0; rI < row; ++rI)
      delete[] data[rI];
    delete[] data;

    row = m.getRowCnt();
    col = m.getColCnt();

    data = new mT*[row];
    for (int rI = 0; rI < row; ++rI)
    {
      data[rI] = new mT[col];
      for (int cI = 0; cI < col; ++cI)
        data[rI][cI] = m[rI][cI];
    }
  }
  else
  {
    for (int rI = 0; rI < row; ++rI)
    {
      for (int cI = 0; cI < col; ++cI)
        data[rI][cI] = m[rI][cI];
    }
  }

  return (*this);
}


void Matrix::Print(const char * s) const
{
  cout << s << endl;
  for (int iRow = 0; iRow < row; iRow++)
  {
    for (int iCol = 0; iCol < col; iCol++)
    {
      cout << setw(5) << data[iRow][iCol] << " ";
    }
    cout << "" << endl;
  }
}

mT * Matrix::operator[](size_t ind)
{
  return data[ind];
}

const mT * Matrix::operator[](size_t ind) const
{
  return data[ind];
}






Matrix operator+(const Matrix & m1, const Matrix & m2)
{
  if (m1.getColCnt() != m2.getColCnt() || m1.getRowCnt() != m2.getRowCnt())
  {
    cout << "MATRIX plus MATRIX DIMENSION ERROR" << endl;
    return Matrix();
  }

  Matrix res(m1.getRowCnt(), m1.getColCnt());

  for (int rI = 0; rI < res.getRowCnt(); ++rI)
  {
    for (int cI = 0; cI < res.getColCnt(); ++cI)
    {
      res[rI][cI] = m1[rI][cI] + m2[rI][cI];
    }
  }

  return res;
}

Matrix operator-(const Matrix & m1, const Matrix & m2)
{
  if (m1.getColCnt() != m2.getColCnt() || m1.getRowCnt() != m2.getRowCnt())
  {
    cout << "MATRIX minus MATRIX DIMENSION ERROR" << endl;
    return Matrix();
  }

  Matrix res(m1.getRowCnt(), m1.getColCnt());

  for (int rI = 0; rI < res.getRowCnt(); ++rI)
  {
    for (int cI = 0; cI < res.getColCnt(); ++cI)
    {
      res[rI][cI] = m1[rI][cI] - m2[rI][cI];
    }
  }

  return res;
}


Matrix operator*(const Matrix & m1, mT a)
{
  Matrix res(m1.getRowCnt(), m1.getColCnt());

  for (int rI = 0; rI < res.getRowCnt(); ++rI)
  {
    for (int cI = 0; cI < res.getColCnt(); ++cI)
    {
      res[rI][cI] = m1[rI][cI] * a;
    }
  }

  return res;
}

Matrix operator*(mT a, const Matrix & m1)
{
  Matrix res(m1.getRowCnt(), m1.getColCnt());

  for (int rI = 0; rI < res.getRowCnt(); ++rI)
  {
    for (int cI = 0; cI < res.getColCnt(); ++cI)
    {
      res[rI][cI] = m1[rI][cI] * a;
    }
  }

  return res;
}

Vec operator*(const Matrix & m, const Vec & v)
{
  if (m.getColCnt() != v.getSize())
  {
    cout << "MATRIX mul VEC DIMENSION ERROR" << endl;
    return Vec();
  }

  Vec res(m.getRowCnt());

  for (int rI = 0; rI < m.getRowCnt(); ++rI)
  {
      mT sum = 0.0;
      for (int ind = 0; ind < m.getColCnt(); ++ind)
      {
        sum += m[rI][ind] * v[ind];
      }
      res[rI] = sum;
  }

  return res;
}

Vec operator*(const Vec & v, const Matrix & m)
{
  if ( v.getSize() != m.getRowCnt())
  {
    cout << "Vec mul Matrix DIMENSION ERROR" << endl;
    return Vec();
  }

  Vec res(m.getColCnt());

  for (int cI = 0; cI < m.getColCnt(); ++cI)
  {
    mT sum = 0.0;
    for (int ind = 0; ind < m.getRowCnt(); ++ind)
    {
      sum += m[ind][cI] * v[ind];
    }
    res[cI] = sum;
  }

  return res;
}



Matrix operator*(const Matrix & m1, const Matrix & m2)
{
  if (m1.getColCnt() != m2.getRowCnt())
  {
    std::cout << "MATRIX mul MATRIX DIMENSION ERROR" << std::endl;
    return Matrix();
  }

  Matrix res(m1.getRowCnt(), m2.getColCnt());

  for (int rI = 0; rI < m1.getRowCnt(); ++rI)
  {
    for (int cI = 0; cI < m2.getColCnt(); ++cI)
    {
      mT sum = 0.0;
      for (int ind = 0; ind < m1.getColCnt(); ++ind)
      {
        sum += m1[rI][ind] * m2[ind][cI];
      }
      res[rI][cI] = sum;
    }
  }

  return res;
}