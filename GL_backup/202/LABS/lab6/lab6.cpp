#include <iostream>
#include <cstdlib>
#include "fraction.h"
using namespace std;

int main(int argc, char *argv[]){
  fraction fracRec;
  fraction frac1(atoi(argv[1]),atoi(argv[2]));
  fracRec = frac1.Reciprocal();
  frac1.Output();
  fracRec.Output();
  fraction frac2;
  frac2.Output();
  fraction frac3(1,0);
  

}
