#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;
template <class T>
class Rectangle{

  //  friend ostream &operator << (ostream &os, const Rectangle &n);
 public:
  Rectangle();
  Rectangle(int length, int width);
  void SetWidt(T width);
  void SetLength(T length);
  T GetWidth();
  T GetLength();
  T GetArea();
  T GetPerimeter();
  T GetDiagonal();
  T IsSquare();
  Rectangle& operator=(const Rectangle& rhs);
 
 private:
  T length;
  T width;
};

#endif
