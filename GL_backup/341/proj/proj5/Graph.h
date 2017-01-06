/**************************************************************                
 * File:    Graph.h                                                        
 * Project: CMSC 341 - Project 5                                               
 * Author : Neh Patel                                                          
 * Date   : 27-November-2014                                                   
 * Section: Lecture-02                                                         
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                             
 *  This is the header file of the Graph class. 
 *  Nodes with no value are assigned as -1. not 0
 *   
 *************************************************************/
#ifndef GRAPH
#define GRAPH
#include <iostream>
using namespace std;
#include <string>
#include <vector>

struct Node{
  int NodeNumber;
  vector<int> PathTo;
  vector<int> PathCost;
  bool Visited;
};
class Graph{
 public:
  ////////////////////  IN GRAPH.CPP  ////////////////////////////
  Graph( string filename );
  ~Graph( );
  int trips( int sourceCity, int destinationCity, int tourists );
  void ReadFile( string file );
  void MakeVectors( );
  void MakeGraph( );
  void PrintGraph() const;
  void BFS(int current);
  int FindPath(int t);

  ////////////////////  IN GRAPH.H  //////////////////////////////
  
  /**************************************************************              
   MAKE EMPTY
     sets everything to zero. Used in destructor. Can be used 
     to delete the graph 
   *************************************************************/  
  void makeEmpty(){
    NodeHolder.clear();
    Parent.clear();
    Cost.clear();
    numbers.clear();
    GraphP.clear();
    GraphC1.clear();
    GraphC2.clear();
    startCity = -1;
    destination = -1;
  }

  /**************************************************************             
    IS EMPTY
       checks if the graph is empty or not
   *************************************************************/
  bool isEmpty(){
    if(NodeHolder.empty()){
      return true;
    }
    return false;
  }

  /**************************************************************             
    SEARCH NODE                                                              
          takes in the Node number and spits out the index number 
          of where that node is
   *************************************************************/
  int SearchNode( int NodeNum ){
    for(int i = 0; i <(signed)NodeHolder.size();i++){
      if(NodeHolder[i].NodeNumber == NodeNum){
	return i;
      }
    }
    return -1;
  }

 private:
  string file;
  int Cities;
  int Roads;
  vector<int> numbers;
  vector<int> GraphC1;
  vector<int> GraphC2;
  vector<int> GraphP;
  vector<Node> NodeHolder;
  vector<int> Parent;
  vector<int> Cost;
  int cost;
  /*
  struct Node{
    int NodeNumber;
    vector<Node*> PointTo;
    vector<int> PathCost;
    };*/
  int startCity;
  int destination;
};

#endif
