/**************************************************************                
 * File:    Vehicle.cpp                                                        
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation                    
 * Author : Neh N. Patel                                                       
 * Date   : Sept 29                                                            
 * Section: 2                                                                  
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                            
 * Vehicle class. Makes an object vehicle to tell if it is a                   
 * car or a truck. This is a source file (.cpp). Probably                      
 * not a good extensive object file for cars                                    *                                                                             
 *************************************************************/


#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(char type1){
  type = type1;
}

// Gets the type of the vehicle (car/truck)
// accessor
char Vehicle::GetType() const{
  return type;
}

//mutator 
// changes the type of the vehicle 
void Vehicle::SetChar(char type1){
  type = type1;
}

//the moment the car entered the intersection
int Vehicle::timeEntered(){
  return 0;
}
// setting the time 
void Vehicle::SetTime(int time){}

