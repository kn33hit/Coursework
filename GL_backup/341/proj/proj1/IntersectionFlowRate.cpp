/**************************************************************      
 * File:    IntersectionFlowRate.cpp               
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation                    
 * Author : Neh N. Patel                                                       
 * Date   : Sept 29                                                            
 * Section: 2                                                                  
 * E-mail:  npatel10@umbc.edu                                                 
 *                                                                             
 * this class keeps track of the flow rate in each direction              
 *                                                                             
 *************************************************************/

#include "IntersectionFlowRate.h"
#include <iostream>
using namespace std;


//CONSTRUCTOR 
// does ntohing but create the object 
IntersectionFlowRate::IntersectionFlowRate(){}


// ACCESSORS 
// for all of them they just fetch the info 
// Pre for all is none
// Post for all is the returned variable 
int IntersectionFlowRate::GetEastCars()const{
  return eastCars;
}

int IntersectionFlowRate::GetWestCars()const{
  return westCars;
}

int IntersectionFlowRate::GetNorthCars()const{
  return northCars;
}

int IntersectionFlowRate::GetSouthCars()const{
  return southCars;
}

int IntersectionFlowRate::GetEastTrucks()const{
  return eastTrucks;
}

int IntersectionFlowRate::GetWestTrucks()const{
  return westTrucks;
}

int IntersectionFlowRate::GetNorthTrucks()const{
  return northTrucks;
}

int IntersectionFlowRate::GetSouthTrucks()const{
  return southTrucks;
}



// MUTATORS 
// use them to change the values in the object 
// pre: needs a variable passed in for it t change it 
// post: changes the value for that object 
void IntersectionFlowRate::SetEastCars(int num){
  eastCars = num;
}

void IntersectionFlowRate::SetWestCars(int num){
  westCars = num;
}

void IntersectionFlowRate::SetNorthCars(int num){
  southCars = num;
}

void IntersectionFlowRate::SetSouthCars(int num){
  northCars = num;
}

void IntersectionFlowRate::SetEastTrucks(int num){
  eastTrucks = num;
}

void IntersectionFlowRate::SetWestTrucks(int num){
  westTrucks = num;
}

void IntersectionFlowRate::SetNorthTrucks(int num){
  northTrucks = num;
}

void IntersectionFlowRate::SetSouthTrucks(int num){
  southTrucks = num;
}

