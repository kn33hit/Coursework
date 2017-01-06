#include "Graph.h"

int main(int argc, char *argv[])
{
  //read the command line argument and generate a graph                         
  string filename = argv[1];
  Graph mygraph(filename);
  mygraph.process();
}
