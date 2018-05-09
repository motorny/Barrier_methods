#pragma once
typedef double mT;

class Vec
{
private:
  int size = 0;
public:
  mT * data;
  Vec();
  Vec(int size);
  Vec(const Vec &v);
  Vec& operator=(const Vec& v);
  ~Vec();

  mT Norm();
  void SetZeros();

  void Print(const char * s) const;

  int getSize() const {
    return size;
  }

  mT& operator[](size_t ind);
  mT operator[](size_t ind) const;
};

Vec operator + (const Vec &v1, const Vec &v2);
Vec operator - (const Vec &v1, const Vec &v2);
Vec operator * (const Vec &v1, mT a);
Vec operator * (mT a, const Vec &v1);
mT operator * (const Vec &v1, const Vec &v2);

