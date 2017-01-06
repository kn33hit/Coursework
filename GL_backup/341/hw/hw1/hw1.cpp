/*===================================================================
/File: hw1.cpp
/Author: Neh Patel 
/Date: Sept. 11,2014 
/Section: 
/Description: driver file for the twodimensional and three dimensional 
/             object classes. Basically creates a 3D point and 
/             is assigned to a pointer. Then creates a dynamic array
/             consisting of 10 3d points
/
/==================================================================*/

#include "TwoDimensional.h"
#include "ThreeDimensional.h"
// include the next two to include random function to generate random numbers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
  // creating a 2D object just to test
  TwoDimensional one(1.1,1.2);
  // another object created to make the pointer of 3d point and have the 
  // address assigned to it 
  ThreeDimensional a(3.0,4.0,5.0);
  ThreeDimensional* firstPt = &a;
  
  // printing out the pointer to test the << overloaded function
  cout << *firstPt << endl;
  // practice purposes 
  //  cout << one.getX() << endl;
  //  cout << one.getY() <<endl;
  //  cout << a.getX() <<endl;
  //  cout << a.getY() <<endl;
  //  cout << a.getZ() <<endl;  
  
  // creating a new dynamic array with 10 3D points 
  ThreeDimensional *array = new ThreeDimensional[10];
  for(int i = 0; i < 10;i++){
    // rand() % 20 creates number from 0-19. and then subtracting 10 gives us 
    // -9 to 9
    ThreeDimensional b(rand()%20-10,rand()%20-10,rand()%20-10);
    array[i] = b;
    cout << b << endl;
  }
   
  // every new needs a delete 
  delete [] array;
  array = NULL;
}
