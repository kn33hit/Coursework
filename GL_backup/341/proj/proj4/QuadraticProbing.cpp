/**************************************************************                
 * File:    QuadraticProbing.cpp
 * Project: CMSC 341 - Project 4                               
 * Author : Neh Patel                                                          
 * Date   : 16-November-2014                                                   
 * Section: Lecture-02                                                         
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                             
 * Implementation of the Quadratic Probing class. x
 *                                                                             
 *************************************************************/

#include "QuadraticProbing.h"
#include <math.h>
#include <fstream>
 
/************************************************************                    CONSTRUCTOR                                                                       creates the object and sets everything to zero. Takes a       
   vector and places 0 as empty buckets. and takes in the size                        
 **********************************************************/
QuadraticProbing::QuadraticProbing(int m){
  // need size to make the table
  size = m;
  HashTable.resize(m);
  successData = -1;
  unsuccessData = 0;
  lambda = 0;
  probes = 0;
  maxProbes = 0;
}
 
/************************************************************            
   INSERT                                                                           just made to make sense when someone wantst to insert        
    something. Calls Handle Collisions which actually            
    does all the work                                                           
                                                                                                                                                             
 **********************************************************/
void QuadraticProbing::insert(const int number){
    HandleCollision( number);
}
 
/************************************************************                                                                                             
   HANDLE COLLISIONS                                                                takes in the key. uses the linear function and accounts      
    for the output results. And inserts values into the          
    hash table                                                        
                                                                                                                                                             
 **********************************************************/
void QuadraticProbing::HandleCollision( const int number){
  // QUADRATIC: H(K,I) = (H(K) + I^2) MOD M     
  bool flagInserted = true;
  // i used to increment throught the loop
  int i = 1;
  // need function agian here. just double checking. and need to add 
  // same value later on
  int index = number % size;
  int newIndex = index;
  maxProbes = 0;
  while(flagInserted){
    //    probes++;
    // base case, if spot is opne: insert value and leave
    if(HashTable[newIndex] == 0){
      HashTable[newIndex] = number;
      successData++;
      maxProbes++;
      break;
    }else{
      // use this function(also at top of this fucntion, to find next spot
      int power = pow(i,2);
      // % suze same here
      newIndex = (index + power) % size;
      maxProbes++;
      probes++;
      i++;
    }   
    // another case where once you go through everything you're done 
    if(newIndex == index){
      unsuccessData++;
      break;
    }
  }
}
 
/************************************************************                                                                                               
    OUTPUT RESULTS                                                                    writes the actual table to the outputTable.txt             
      file                                                                                                                                               
 **********************************************************/
void QuadraticProbing::OutputResults(){  
  fstream outfile;
  outfile.open("outputTable.txt", fstream::in | fstream::out | fstream::app);
  outfile << "Quadratic Probing actual table" << endl;
  for(int i = 0; i < size; i++){
    if(HashTable[i] != 0){
      outfile << i << ": " <<  HashTable[i] << endl;
    }else{
      outfile << i << ":" << endl;
    }
  }
  outfile << endl;
  outfile.close();
}

