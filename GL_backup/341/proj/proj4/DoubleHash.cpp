/**************************************************************                
 * File:    DoubleHash.cpp
 * Project: CMSC 341 - Project 4                                               
 * Author : Neh Patel                                                          
 * Date   : 16-November-2014                                                   
 * Section: Lecture-02                                                         
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                             
 *  implemetation of the Double Hash object.        
 *                                                                             
 *************************************************************/

#include "DoubleHash.h"
#include <fstream>

/*************************************************************
  CONSTRUCTOR
     creates the object and sets everything to zero. Takes a       
   vector and places 0 as empty buckets. and takes in the size  
*************************************************************/
DoubleHash::DoubleHash(int m,int r){
  // r used in hash 2 fucntion
  R = r;
  // used to make the table
  size = m;
  HashTable.resize(m);
  successData = 0;
  unsuccessData = 0;
  lambda = 0;
  probes = 0;
  maxProbes = 0;
}

/*************************************************************
   INSERT
      just made to make sense when someone wantst to insert        
    something. Calls Handle Collisions which actually            
    does all the work   

*************************************************************/
void DoubleHash::insert(const int number){
  HandleCollision( number);
}

/*************************************************************
  HANDLE COLLISION
     takes in the key. uses the linear function and accounts      
    for the output results. And inserts values into the          
    hash table

*************************************************************/
void DoubleHash::HandleCollision( const int number){
  // DOUBLE: H(K,I) = (H(K) + I* H2(K)) MOD M                              
  // H2: (K) = R - (K MOD R)  
  // flag used to keep moving forward if spot is taken
  bool flagInserted = true;
  int i = 1;
  int H2;
  // since index needs to stay constant we take a temporary index variable
  // to use as the new index to check 
  int index = number % size;
  int newIndex = index;
  maxProbes = 0;
  while(flagInserted){
    // first case:if spot emprty, insert number and leave.
    probes++;
    if(HashTable[newIndex] == 0){
      HashTable[newIndex] = number;
      successData++;
      maxProbes++;
      break;
      // if not apply the hash function and keep going 
    }else{
      H2 = R - (number % R);
      newIndex = (index + (i * H2)) % size;
      maxProbes++;
      i++;
    }
    // this case is used so we dont get stuck in a infinate loop
    // as we dont have load factor. we would stop looking for a place 
    // once we go around the table once, we need to stop 
    if(newIndex == index){
      //      probes++;
      unsuccessData++;
      break;
    }
  }
}
 
  /*************************************************************
     OUTPUT RESULTS
      writes the actual table to the outputTable.txt             
      file 
  *************************************************************/
void DoubleHash::OutputResults(){  
  // writing to output file. Since only this class has access to the 
  // actual table we need to do this part from here
  fstream outfile;
  outfile.open("outputTable.txt", fstream::in | fstream::out | fstream::app);
  outfile << "Double Hashing actual table" << endl;
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

