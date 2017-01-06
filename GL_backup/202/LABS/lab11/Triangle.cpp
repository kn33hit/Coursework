#include "Triangle.h"
#include "Shape.h"
#include <iostream>

using namespace std;

Triangle::Triangle(int l = 0, int h=0){
  m_l = l;
  m_h = h;
}

int Triangle::GetArea() const{
  return (m_l * m_h / 2);
}
void Triangle::Draw() const{
  cout << "Drawing a triangle" << endl; 
}

Triangle::~Triangle()
{} 
