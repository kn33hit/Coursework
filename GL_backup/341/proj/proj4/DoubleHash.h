/**************************************************************                
 * File:    DoubleHash.h                                               
 * Project: CMSC 341 - Project 4                               
 * Author : Neh Patel                                                          
 * Date   : 16-November-2014                                                   
 * Section: Lecture-02                                                         
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                             
 * Header Double Hash class. Used a vector to store data, 
 * then insertiona handles the algorithm to make it into a 
 * hash table                                                   
 *                                                                             
 *************************************************************/

#ifndef DOUBLE_HASH
#define DOUBLE_HASH
#include <iostream>
#include <vector>
using namespace std;

class DoubleHash{
 public:
  DoubleHash( int m , int r );
  void insert( int number );
  void HandleCollision( const int number );
  void OutputResults();

/*************************************************************  
    GET NUM OF DATA IN TABLE 
         returns the number of elements in the table  
 *************************************************************/
 int GetNumOfDataInTable(){
    int count = 0;
    for(int i = 0; i <(signed) HashTable.size();i++){
      if(HashTable[i] != 0){
        count++;
      }
    }
    return count;
  }
 
  /*************************************************************
   GET LAMBDA
     returns the load factor of the table( number of buckets     
     full / elements in the bucket )     
  *************************************************************/
  double GetLambda(){
    return (double)GetNumOfDataInTable() / (double)size;
  }

  /*************************************************************
    GET TOTAL PROBES 
       returns the total number of probing that has             
        currently occured   
   *************************************************************/
  int GetTotalProbes(){
    return probes;
  }

  /*************************************************************
    GET MAX PROBES 
    returns the max number of probes that have currently       
      occured    
   *************************************************************/
  int GetMaxProbes(){
    return successData + unsuccessData;
  }

  /*************************************************************
    GET SUCCESS DATA
         returns the total number of successful insertions  
   *************************************************************/
  int GetSuccessData(){
    return successData;
  }

  /*************************************************************
    GET UNSUCCESS DATA
        returns the total number of failure to insert            
        have occured    
   *************************************************************/
  int GetUnSuccessData(){
    return unsuccessData;
  }

  /*************************************************************
     GET CLUSTER
         gets the total number of clusters in the table 

   *************************************************************/
  int GetCluster(){
    clusterV.clear();
    int cluster = 0;
    for(int i = 0; i < (signed)HashTable.size(); i++){
      if(HashTable[i] != 0){
        cluster = 0;
        while(HashTable[i+1] != 0 && (i+1) != (signed)HashTable.size() ){
          i++;
          cluster++;
        }
        cluster++;
	clusterV.push_back(cluster);
      }
    }
    return (signed)clusterV.size();
  }
 
  /*************************************************************
     GET AVG CLUSTER 
          returns the avg size of the cluster
  *************************************************************/
  double GetAvgCluster(){
    double total;
    for(int i = 0; i < (signed)clusterV.size() ; i++){
      total+= clusterV[i];
    }
    double clusterAvg = total / (double)(signed)clusterV.size();
    return clusterAvg;
  }

  /*************************************************************
    GET MAX CLUSTER
        returns the max size of a  cluster in the table 
  *************************************************************/
  int GetMaxCluster(){
    int max = 0;
    for(int i =0; i < (signed)clusterV.size(); i++){
      if(clusterV[i] > max){
        max = clusterV[i];
      }
    }
    return max;
  }

 private:
  vector<int> clusterV;
  int clusterAvg;
  vector<int> HashTable;
  int size;
  int R;  // only for this class 
  double lambda; // elements / total space                                    
  int numOfDataInTable;
  int maxProbes;
  int probes;
  int successData;
  int unsuccessData;
};

#endif
