/**************************************************************                
 * File:    LinearProbing.cpp      
 * Project: CMSC 341 - Project 4                               
 * Author : Neh Patel                                                          
 * Date   : 16-November-2014                                                   
 * Section: Lecture-02                                                         
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                             
 * Implementation of the Linear Probing class. 
 *                                                                             
 *************************************************************/

#include "LinearProbing.h"
#include <fstream>
 
/************************************************************                                                                                              
 CONSTRUCTOR 
   creates the object and sets everything to zero. Takes a 
   vector and places 0 as empty buckets. and takes in the size

 **********************************************************/
LinearProbing::LinearProbing(int m){
  // need size here to make the table 
  size = m;
  HashTable.resize(m);
  successData = 0;
  unsuccessData = 0;
  lambda = 0;  
  probes = 0;
  maxProbes = 0;
  // since table is currently empty. treats data as 0
}
  
/************************************************************  
  INSERT                                                            just made to make sense when someone wantst to insert 
    something. Calls Handle Collisions which actually 
    does all the work

 **********************************************************/
void LinearProbing::insert(const int number){
  HandleCollision( number);
}
 
/************************************************************  
  HANDLE COLLISION
    takes in the key. uses the linear function and accounts 
    for the output results. And inserts values into the 
    hash table 
 **********************************************************/
void LinearProbing::HandleCollision( const int number){
  // LINEAR:H(K,I) = (H(K) + I) MOD M    
  int i = 1;
  // H(K): size (constant)
  int index = number % size;
  // another h(k) but is change throghout 
  int newIndex = index;
  maxProbes= 0;
  while(1){
    // cout << index << " = " << number << " % " << size << endl;
    // first case: if the spot is open, break out, and insert value 
    if(HashTable[newIndex] == 0){
      HashTable[newIndex] = number;
      successData++;
      maxProbes++;
      break;
     }else{
      // if spot not open. check the spot under it using this function
   
      newIndex = (index + i) % size;
      probes++;
      maxProbes++;
      i++;
    }
    // once you go through the whole table exit. this case helps us do that
    if(isFull() == true){
      unsuccessData++;
      break;
    }
  }
}
/************************************************************
  IS FULL 
      checks if the table is full or not and returns true 
     if it is 
 
************************************************************/ 
  bool LinearProbing::isFull(){
    int count = 0;
    for(int i = 0 ; i < (signed)HashTable.size();i++){
      if(HashTable[i] != 0){
	count++;}
    }
    if(count == (signed)HashTable.size()){
      return true;
    }
    return false;
  }
/************************************************************                                                                                             
   OUTPUT RESULTS 
      writes the actual table to the outputTable.txt 
      file
 **********************************************************/
void LinearProbing::OutputResults(){
  // outputting the actula table to a file 
  ofstream outfile;
  outfile.open("outputTable.txt");
  outfile << "Linear Probing actual table" << endl;
  // hashtable is the parameter that holds all the values as a hash table
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
