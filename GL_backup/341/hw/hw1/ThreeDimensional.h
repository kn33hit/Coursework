/*===================================================================          
/File: hw1.cpp                                                                 
/Author: Neh Patel                                                             
/Date: Sept. 11,2014                                                           
/Section:                                                                       
/Description: 3D object file which contains all the prototypes for the objects
              attributes. and also include an overloaded << for the object 
/                                                                              
/==================================================================*/

#ifndef THREEDIMENSIONAL_H
#define THREEDIMENSIONAL_H
#include "TwoDimensional.h"
#include <iostream>
using namespace std;

class ThreeDimensional: public TwoDimensional{
 private:
  double x, y, z; // x, y, z coordinates

 public:
  // ThreeDimensional(double i, double j, double k):x(i), y(j), z(k){} 
  ThreeDimensional();
  ThreeDimensional(double x,double y,double z);
  void setZ(double NewZ);
  void setX(double NewX);
  void setY(double NewY);
  double getZ() const;
  double getX() const;
  double getY() const;
  ThreeDimensional& operator=(const ThreeDimensional& rhs);
  friend ostream& operator<< (ostream &os, const ThreeDimensional& x)
  {
    os << "This 3D point has teh values of:" << endl;
    os << "x: " << x.getX() << endl;
    os << "y: " << x.getY() << endl;
    os << "z: " << x.getZ() << endl;
    os << "---" << endl;
  }
};

#endif

