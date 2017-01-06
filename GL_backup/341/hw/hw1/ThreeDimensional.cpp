/*===================================================================          
/File: hw1.cpp                                                                 
/Author: Neh Patel                                                             
/Date: Sept. 11,2014                                                           
/Section:                                                                    
/Description: the source file for the 3D point object. states:(x,y,z)
              functions: accessors, mutators, copy constructor, etc.
/                                                                              
/==================================================================*/

#include "ThreeDimensional.h"
#include <iostream> 
using namespace std;

ThreeDimensional::ThreeDimensional(){
  x = 1;
  y = 1;
  z = 0;
}

ThreeDimensional::ThreeDimensional(double a, double b, double c) : \
  TwoDimensional(a,b){
  x = a;
  y = b;
  z = c;
}

void ThreeDimensional::setZ(double NewZ){
  z = NewZ;
}

double ThreeDimensional::getZ() const{
  return z;
}

void ThreeDimensional::setX(double NewX){
  x = NewX;
}

double ThreeDimensional::getX() const{
  return x;
}

void ThreeDimensional::setY(double NewY){
  y = NewY;
}

double ThreeDimensional::getY() const{
  return y;
}

ThreeDimensional& ThreeDimensional::operator=(const ThreeDimensional& rhs){
  x = rhs.x;
  y = rhs.y;
  z = rhs.z;
  return *this;
}

