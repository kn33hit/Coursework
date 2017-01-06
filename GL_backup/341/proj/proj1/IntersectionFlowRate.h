/**************************************************************     
 * File:    IntersectionFlowRate.h        
 * Project: CMSC 341 - Project 1 - Traffic Light Simulation                    
 * Author : Neh N. Patel                                                       
 * Date   : Sept 29                                                            
 * Section: 2                                                                  
 * E-mail:  npatel10@umbc.edu                                                
 *                                                                             
 * this class keeps track of the flow rate in each direction                   
 *                                                                             
 *************************************************************/



#ifndef INTERSECTIONFLOWRATE_H
#define INTERSECTIONFLOWRATE_H

class IntersectionFlowRate{
 public:
  IntersectionFlowRate();
  int GetEastCars()const;
  int GetWestCars()const;
  int GetNorthCars()const;
  int GetSouthCars()const;
  int GetEastTrucks()const;
  int GetWestTrucks()const;
  int GetNorthTrucks()const;
  int GetSouthTrucks()const;
  void SetEastCars(int num);
  void SetWestCars(int num);
  void SetNorthCars(int num);
  void SetSouthCars(int num);
  void SetEastTrucks(int num);
  void SetWestTrucks(int num);
  void SetNorthTrucks(int num);
  void SetSouthTrucks(int num);


 private:
  int eastCars, westCars,northCars,southCars;
  int eastTrucks,westTrucks,northTrucks,southTrucks;
};

#endif 
