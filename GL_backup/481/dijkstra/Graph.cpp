#include "Graph.h"
#include <fstream>
#include <stdlib.h>
#include <queue>
#include <math.h>
#include <algorithm>

void Graph::process(){
  findPath(start);
  PrintResults();
}

Graph::Graph(string filename){
  for(int i = 0; i < ARRAY_SIZE;i++){
    visited[i] = 0;
    parent[i] = -1;
    for(int j = 0; j < ARRAY_SIZE;j++){
      GraphArray[i][j] = -1;
    }
  }
  ReadFile(filename);
  MakeGraph();
}

Graph::~Graph(){
}

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
  string line;
  while(infile >> line){
    input.push_back(line);
  }
  infile.close();
}

void Graph::MakeGraph(){
  for(int i = 0; i < (signed)input.size() - 2;i++){
    // cout << "-------------------------------------------" << endl;
    string temp = input[i];
    int Node1 = temp[0] - '0';
    int Node2 = temp[2] - '0';
    int Cost = temp[4] - '0';
    GraphArray[Node1][Node2] = Cost;
    GraphArray[Node2][Node1] = Cost;
  }
  string temp = input[(signed)input.size() - 2];
  start = temp[temp.length() - 1] - '0';
  temp = input[(signed)input.size() - 1];
  destination = temp[temp.length() - 1] - '0';
}

void Graph::PrintGraph() const{
  cout << "START: " << start << endl;
  cout << "END: " << destination << endl;
  for(int i = 0; i < ARRAY_SIZE;i++){
    for(int j = 0; j < ARRAY_SIZE;j++){
      if(GraphArray[i][j] != -1){
	cout << "Node " << i << " connected to " << j << endl;
	cout << "Cost: " << GraphArray[i][j] << endl;
      }
    }
  }
}


void Graph::findPath(int source){
  SetDefault();
  queue<int> path;
  vector<int> tempCost;
  int main;
  main = source;
  path.push(source);
  parent[source] = 0;
  cost[source] = 0;
  path.push(source);

  while( !path.empty() ){
    source = path.front();
    visited[source] = 1;
    path.pop();
    int distance = 999;
    for(int i = 0; i < ARRAY_SIZE; i++){
      if(GraphArray[source][i] != -1 && visited[i] != 1 && \
	 GraphArray[source][i] + cost[source] < distance){
	distance = GraphArray[source][i] + cost[source];
	cost[i] = distance;
	parent[i] = source;
	path.push(i);
      }
      if(cost[i] == 0 && GraphArray[source][i] != -1){
	parent[i] = source;
	cost[i] = GraphArray[source][i] + cost[source];
	path.push(i);
      }
    }
  }
  
  if(main == start){
    for(int i = 0; i < ARRAY_SIZE;i++){
      cout << "NODE: " << i << endl;
      cout << "PARENT: " << parent[i] << endl;
      cout << "COST: " << cost[i] << endl;
      cout << "-----------------------------------------------" << endl;
    }  
  }
}


int Graph::findMinDistanceNode(int node){
  int nextNode = -1, minDistance = 999;
  for(int i = 0; i < ARRAY_SIZE; i++){
    if(GraphArray[node][i] != -1 && GraphArray[node][i] <\
       minDistance && visited[i] != 1){
      minDistance = GraphArray[node][i];
      nextNode = i;
    }
  }
  visited[nextNode] = 1;
  cout << "The parent of " << nextNode << " is " << node << endl;
  parent[nextNode] = node;
  return nextNode;
}

void Graph::SetDefault(){
  for(int i = 0; i < ARRAY_SIZE; i++){
    visited[i] = 0;
    parent[i] = 999;
    cost[i] = 0;
  }
}


void Graph::PrintResults(){
  int temp [] = { 0, 0, 1, 4, 1, 2, 2, 4, 6 , 8};
  queue<int> tempqueue;
  vector<int> tempVec;
  ofstream ofile;
  ofile.open("output.txt");
  int i = 0;
  int k;
  i = destination;
  ofile << "The route from " << start << " to " << destination << ": " << endl;
  while(i != 0){
    tempqueue.push(i);
    // TEMP
    i = temp[i]; 
  }
  for(int i = 0; i < (signed)tempqueue.size() ;i++){
    ofile << tempqueue.front() << " -> " ;
    tempqueue.pop();
  }
  
  if(!tempqueue.empty()){
    ofile << tempqueue.front() << endl ;
    tempqueue.pop();
  }

  ofile << "Total Distance: " << cost[destination] << endl;
  ofile<< "------------------------------------------------------------"<<endl;
  
  for(int i = 1; i < 9;i++){
    findPath(i);
    ofile << "Routing table of node "<< i << endl;
    ofile << " To         Next Hop            Distance" << endl;;   
    //findPath(i);
    for(int j = 1; j < 9; j++){
      if( i != j){
	k = j;
	while(k != 0){
	  tempVec.push_back(k);
	  // TEMP
	  k = temp[k];
	}
       
	//------
	ofile << " " << j << "             " << tempVec[tempVec.size() - 2] \
	      << "                   " << cost[j] << endl;
	tempVec.clear();
      }
    }
    ofile << endl;
    ofile << endl;

  }
  ofile.close();
}
