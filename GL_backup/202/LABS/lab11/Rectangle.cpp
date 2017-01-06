#include "Rectangle.h"
#include "Shape.h"
#include <iostream>

using namespace std;

Rectangle::Rectangle(int l=0, int w=0){
  m_l = l;
  m_w = w;
}
int Rectangle::GetArea() const{
  return m_l * m_w;
}

void Rectangle::Draw() const {
  cout << "Drawing a rectangle" << endl;
}

Rectangle::~Rectangle(){}
