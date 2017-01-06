#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
// Write the public and private members here
 public: 
  Triangle(int l, int h);
  int GetArea() const;
  void Draw() const;
  ~Triangle();
    private:
  int m_area;
  int m_l;
  int m_h;


};

#endif
