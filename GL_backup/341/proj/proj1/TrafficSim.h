/**************************************************************    
 * File:    TrafficSim.h                                          
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation                    
 * Author : Neh N. Patel                                                       
 * Date   : Sept 29                                                            
 * Section: 2                                                                  
 * E-mail:  npatel10@umbc.edu                                                 
 *                                                                             
 * Base class for the project.The instance of this object is 
 * created in the driver. It uses every object created for this
 * object. uses queues.
 *                                                                             
 *************************************************************/

#include "Linked_List.h"
#include "ResultVehicle.h"
#include "Vehicle.h"
#include "IntersectionFlowRate.h"
#ifndef TRAFFICSIM_H
#define TRAFFICSIM_H
#include <queue>
// # include few other things 

class TrafficSim{
 public :
  TrafficSim();
  TrafficSim(char* filename);
  void DoRun();
  bool ReadFromFile(char* file);
  void printBoard(int sec) const;


 private: 
  char* filename;
  queue<Vehicle> NorthBound;
  queue<Vehicle> SouthBound;
  queue<Vehicle> EastBound;
  queue<Vehicle> WestBound;
  IntersectionFlowRate flow;


};

#endif 
