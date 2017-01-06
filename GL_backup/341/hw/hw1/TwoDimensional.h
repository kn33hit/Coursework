/*===================================================================          
/File: hw1.cpp                                                                 
/Author: Neh Patel                                                             
/Date: Sept. 11,2014                                                           
/Section:                                            
/Description: Two dimensional object header file. just include prototypes     
/                                                                              
/==================================================================*/


#ifndef TWODIMENSIONAL_H
#define TWODIMENSIONAL_H

class TwoDimensional{
 private:
  double x, y; // x and y  coordinates

 public:
  // TwoDimensional(double i, double j):x(i), y(j){}
  TwoDimensional();
  TwoDimensional(double x, double y);
  virtual void setX(double NewX);
  virtual void setY(double NewY);
  virtual double getX() const;
  virtual double getY() const;

};

#endif
