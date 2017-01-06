/*===================================================================          
/File: hw1.cpp                                                                 
/Author: Neh Patel                                                             
/Date: Sept. 11,2014                                                           
/Section:                                                     
/Description: source file for the 2D object only funcitos are accessors and 
   mutators                  
/                                                                              
/==================================================================*/


#include "TwoDimensional.h"
#include <iostream>
using namespace std;


TwoDimensional::TwoDimensional(){
  x = 0;
  y = 0;
}

TwoDimensional::TwoDimensional(double a, double b){
  x = a;
  y = b;
}

void TwoDimensional::setX(double NewX){
  x = NewX;
}

void TwoDimensional::setY(double NewY){
  y = NewY;
}

double TwoDimensional::getY() const{
  return y;
}

double TwoDimensional::getX() const{
  return x;
}
