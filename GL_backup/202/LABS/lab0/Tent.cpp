#include "Tent.h"

using namespace std;


Tent::Tent():Residence(1,2,false){
}

int Tent::PropertyValue(){
  return 0;
}

int Tent::NumWindows(){
  return 0;
}

ostream &operator<<(ostream &out, const Tent &obj)
{
    // Fill the rest of this method in
    // Use this one as a model for the other << operators
  out << "Number of Rooms: 1 "<< '\n';
  out << "Number of Walls: 2" <<'\n';
  out << "Washer: false" << '\n';
  out << "Number of Windows: 0" << '\n';
  out << "Property Value: 0.0";

    return out;
}
