#include "Rectangle.h"
#include <math.h>

#include <iostream>
using namespace std;

template <class T>
Rectangle<T>::Rectangle(){
  length = 1;
  width = 1;
}

template <class T>
Rectangle<T>::Rectangle(int l, int w){
  length = l;
  width = w;
}

template <class T>
T Rectangle<T>::GetArea(){
  return length*width;
}

template <class T>
T Rectangle<T>::GetPerimeter(){
  return (2*length)+(2*width);
}

template <class T>
T Rectangle<T>::GetDiagonal(){
  // equation is sqrt(lenght^2 + width^2)
  
  return sqrt((length * length) + (width * width));
}

template <class T>
T Rectangle<T>::GetWidth(){
  return width;
}

template <class T>
T Rectangle<T>::GetLength(){
  return length;
}

template <class T>
void Rectangle<T>::SetLength(T l){
  length = l;
}

template <class T>
void Rectangle<T>::SetWidth(T w){
  width = w;
}

template <class T>
bool Rectangle<T>::IsSquare(){
  if(length == width){
    return true;
  }
  return false;
}

template <class T>
Rectangle& Rectangle<T>::operator=(const Rectangle& rhs){
  length = rhs.length;
  width = rhs.width;
  return *this;
}
