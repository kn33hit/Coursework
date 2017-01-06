#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <queue>
const int ARRAY_SIZE = 10;


class Graph{
 public:
  ////////////////////  IN GRAPH.CPP  ////////////////////////////              
  Graph( string filename );
  ~Graph( );
  void ReadFile( string file );
  void MakeGraph( );
  void PrintGraph() const;
  void findPath(int src);
  int findMinDistanceNode(int node);
  int SearchNode();
  void PrintResults();
  void process();
 private:
  string file;
  vector<string> input;
  int start;
  int destination;
  int GraphArray[ARRAY_SIZE][ARRAY_SIZE];
  int parent[ARRAY_SIZE];
  bool visited[ARRAY_SIZE];
  int cost[ARRAY_SIZE];
  void SetDefault();
 

};

#endif
