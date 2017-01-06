/**************************************************************                
 * File:    Graph.h                                                            
 * Project: CMSC 341 - Project 5                                               
 * Author : Neh Patel                                                          
 * Date   : 27-November-2014                                                   
 * Section: Lecture-02                                                         
 * E-mail:  npatel10@umbc.edu                                                  
 *                                                                             
 *  This is the source file of the Graph class. Creates a graph
 *  and uses it to create a program that would output the 
 *  number of trips it would take a tourists to get his clients 
 *  across the city from different spots. Uses graphs as a method
 *  to map out the cities to keep track of the trips.
 *                                                                             
 *************************************************************/
#include "Graph.h"
#include <fstream>
#include <stdlib.h>
#include <queue>
#include <math.h>

/**************************************************************
CONSTRUCTOR 
   making the graph. Calls other functions to create it 
 *************************************************************/
Graph::Graph(string filename){
  ReadFile(filename);
  MakeVectors();
  MakeGraph();
  startCity = -1;
  destination = -1;
  cost = 0;
  for(int i = 0; i < Cities; i++){
    Cost.push_back(0);
    Parent.push_back(0);
  }
}
/************************************************************
DESTRUCTOR
   Used to delete the graph
********************************************************/
Graph::~Graph(){
  makeEmpty();
}

/**************************************************************                
READ FILE                                     
   Reads the file and takes the numbers and puts it into one 
   vector. Later the vector is split into more vectors 
 *************************************************************/
void Graph::ReadFile(string file){
  ifstream infile;
  infile.open(file.c_str(),ios_base::in);
  // just to be on a safer side if the file does not open properly  
  if(infile.fail()){
    infile.close();
    // return false if opening the file fails                                  
    cout << "An error occured in opening the file" << endl;
    exit(1);
  }
  int number;
  while(infile >> number){
    numbers.push_back(number);
  }
  infile.close();
}
 
/**************************************************************                
MAKE VECTORS                                                                 
   making basic vectors using the input file. So Algorithm in 
   making the graph is much more simpler to do
*************************************************************/
void Graph::MakeVectors(){ 
  // in input file first two integer in line 1 are cities and roads
  // then per line- 3 numbers. 
  // first int: is city one 
  // second int: is city two
  // third int: the cost between the two cities.
  Cities = numbers[0];
  Roads = numbers[1];
  for(int i = 2; i < (signed)numbers.size();i++){
    // GraphC1 stores the City 1 
    GraphC1.push_back(numbers[i]);
    i++;
    // GraphC2 stores the City 2                                              
    GraphC2.push_back(numbers[i]);
    i++;
    // GraphP stores the cost between the two cities
    GraphP.push_back(numbers[i]);
  }
  for(int i = 0; i <= Cities; i++){
    // These two willl be used in Find Path to figure out lowest cost 
    Parent.push_back(-1);
    Cost.push_back(-1);
  }
}

/**************************************************************                
 MAKE GRAPH            
   Making the actual graph
   Uses Node struct to make a new Node and inserts in 
   NodeHolder. The Node has more vectors in it to have the 
   paths and cost to other Nodes 
   Mostly only Insertions of new Nodes or Update occurs in here
 *************************************************************/
void Graph::MakeGraph(){
  // takes in the int (Node Number)
  // searching per line input 
    for(int i = 0; i <(signed)GraphC1.size() ; i++){
      // Get city 1(c1) and city 2(c2) indexes
	int c1 = SearchNode(GraphC1[i]);
	int c2 = SearchNode(GraphC2[i]);
	// if both are not -1, means they both exist in the map 
	if(c1 != -1 && c2 != -1){
	  // c1/c2 is index returned from SearchNode
	  // taking that node and having new path and cost inserted 
	  // into its matrice
	  NodeHolder[c1].PathTo.push_back(GraphC2[i]);
	  NodeHolder[c2].PathTo.push_back(GraphC1[i]);
	  NodeHolder[c1].PathCost.push_back(GraphP[i]);
	  NodeHolder[c2].PathCost.push_back(GraphP[i]);
	  
	}else if(c1 != -1){ // if c1 is already in graph
	  Node city3;
	  city3.NodeNumber = GraphC2[i];
	  // since c1 already exists we take its node number to push it into 
	  // the new node that is made
	  city3.PathTo.push_back(NodeHolder[c1].NodeNumber);
	  city3.PathCost.push_back(GraphP[i]);
	  city3.Visited = false;
	  NodeHolder.push_back(city3);
	  // inserting data for c1 now
	  NodeHolder[c1].PathTo.push_back(GraphC2[i]);
	  NodeHolder[c1].PathCost.push_back(GraphP[i]);
	  
	}else if(c2 != -1){ // if c2 is in graph
	  Node city4;
	  city4.NodeNumber= GraphC1[i];
	  // since c2 already exists we take its node number to push it into  
	  // the new node that is made                                        
	  city4.PathTo.push_back(NodeHolder[c2].NodeNumber);
	  city4.PathCost.push_back(GraphP[i]);
	  city4.Visited= false;
	  NodeHolder.push_back(city4);
	  // inserting data for c2 now  
	  NodeHolder[c2].PathTo.push_back(GraphC1[i]);
	  NodeHolder[c2].PathCost.push_back(GraphP[i]);
	  
	}else{ 
	  // for random nodes being made to be integreted
	  // this shouldn't be happenning in this project 
	  // This also helps when the graph doesnt exist 
	  Node city5;
          city5.NodeNumber = GraphC1[i];
          city5.PathTo.push_back(GraphC2[i]);
          city5.PathCost.push_back(GraphP[i]);
	  city5.Visited= false;
	  Node city6;
          city6.NodeNumber = GraphC2[i];
          city6.PathTo.push_back(GraphC1[i]);
          city6.PathCost.push_back(GraphP[i]);
	  city6.Visited= false;

          NodeHolder.push_back(city5);
          NodeHolder.push_back(city6);
  
	}
    } // end for
}

/**************************************************************                
BFS 
   Using the Breadth First Algorithm with queues we make 
   adjacency list with it to get the path and cost from
   start city to destination 
 *************************************************************/
void Graph::BFS(int current){
  current = current - 1;
  queue<int> path;
  path.push(current);
  NodeHolder[path.front()].Visited = true;
  while(!path.empty()){
    int check = path.front();
    path.pop();
    cout << "Current Node " << NodeHolder[check].NodeNumber << endl;
    cout << NodeHolder[check].Visited << endl;
    for(int i = 0; i < (signed)NodeHolder[check].PathTo.size();i++){
      if(!NodeHolder[NodeHolder[check].PathTo[i-1]].Visited){
	path.push(NodeHolder[NodeHolder[check].PathTo[i-1]].NodeNumber);
	NodeHolder[NodeHolder[check].PathTo[i-1]].Visited = true;
	cout << "checking .. " << endl;
	cout << "    " << NodeHolder[NodeHolder[check].PathTo[i-1]].NodeNumber << endl;
	//int num = NodeHolder[current - 1].NodeNumber;
        //NodeHolder[NodeHolder[current-1].PathTo[i]].Visited = true;
	if(cost < NodeHolder[check].PathCost[i]){
	  cost = NodeHolder[check].PathCost[i];
	}	
	if(destination == check){
	  cout << "destination == " << check << endl;
	  break;
	}

      }
    }
    path.pop();
    Cost.push_back(cost);
    for(int i = 1; i < (signed)NodeHolder.size(); i++){
      if(startCity != NodeHolder[i].NodeNumber){
	NodeHolder[i].Visited = false;
      }
    }
  }
}
  /*
  // TESTING THE PARALLEL ARRAYS
  for(int i = 0; i <= Cities; i++){
    cout << "Parent array " << endl;
    cout << i << ": " <<Parent[i] << endl;
    cout << "Cost array " << endl;
    cout << i << ": " << Cost[i] << endl;
    }*/

 
/**************************************************************                
PRINT GRAPH
   Just Prints all the Nodes in the Graph. WHat it is connected to 
   and the cost between them 
 *************************************************************/
void Graph::PrintGraph() const {
  for(int i = 0; i < (signed)NodeHolder.size(); i++){
    cout << endl;
    cout << NodeHolder[i].NodeNumber << endl;
    cout << "Visited: " << NodeHolder[i].Visited << endl;
    for(int j = 0; j < (signed)NodeHolder[i].PathTo.size(); j++){
      cout << "Connected to " << NodeHolder[i].PathTo[j] << endl;
      cout << "Cost between " << NodeHolder[i].NodeNumber << " and " <<	\
	NodeHolder[i].PathTo[j] << " is " << NodeHolder[i].PathCost[j] << endl;
    }
  }
}

/**************************************************************                
FIND PATH
    With the adjacency lists already made in BFS 
    this method will help us pull out the lowest number 
    from the cost and use it to estimate the the total numbers 
    of trips required
 Pre
   needs BFS to be called first. Or This thing will go haywire
 *************************************************************/
int Graph::FindPath(int tourists){
  // This vector stores the actual costs from start city to 
  // destination
  /*  vector<int> FinalCost;
  FinalCost.push_back(Cost[destination]);
  int newInt = Parent[destination];
  int cost = Cost[newInt];
  FinalCost.push_back(cost);
  // go through till you hit -1 which will only be the start Node
  while(newInt != -1){
    newInt = Parent[newInt];
    cost = Cost[newInt];
    // since our intialization consists of -1 we have to 
    // make sure it is not added to the vector
    // extra protection
    if(cost > 0){
      FinalCost.push_back(cost);
    }
  }
  */
  int lowest = Cost[0];
  // finding the lowest of them all (bottle neck for path)
  cout << "Cost Array" << endl;
  for(int i = 1;i<(signed)Cost.size();i++){
    cout << cost << endl;
    if(lowest > Cost[i]){
      lowest = Cost[i];
    }
  }
  // lowest -1 since we have to account for the guide himself
  double final = ceil(double(tourists) / double(lowest - 1));
  return int(final);
}

/**************************************************************                
TRIPS
   the function being called from the driver.
   Just calls a few more functions
 *************************************************************/
int Graph::trips(int sourceCity, int destinationCity, int tourists){
  startCity = sourceCity;
  destination = destinationCity;
  PrintGraph();
  // We already set the startCity marked as true
  //  NodeHolder[startCity - 1].Visited = true;
  cout <<"start bool " << NodeHolder[startCity - 1].Visited << endl;
  BFS(startCity);
 // all the numbers extracted from the file are in a vector named 
  // numbers (memeber varibale in the class)
  return FindPath(tourists);
}
