/**************************************************************                 * File:    Vehicle.h                 
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation                     * Author : Neh N. Patel                                        
 * Date   : Sept 29                                                       
 * Section: 2                                                                
 * E-mail:  npatel10@umbc.edu                                                
 *                                                                             
 * Vehicle class. Makes an object vehicle to tell if it is a 
 * car or a truck. This is a header file (.h). Probably 
 * not a good extensive object file for cars           
 * 
 *************************************************************/

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle{
 public:
  Vehicle(char type);
  char GetType() const;
  void SetChar(char type); // won't really need this though 
  int timeEntered();
  void SetTime(int time);

 private:
  char type;
  int time;
  int CarWaitTime;
  int TruckWaitTime;
};

#endif 
