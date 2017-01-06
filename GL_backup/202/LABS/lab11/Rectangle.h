#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape
{
// write the public and private members
 public: 
  Rectangle(int l, int w);
  int GetArea() const;
  void Draw() const;
  ~Rectangle();
 private: 
  int m_l;
  int m_w;
  int m_area;
};

#endif
