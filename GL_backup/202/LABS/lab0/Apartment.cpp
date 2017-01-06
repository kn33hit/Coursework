#include "Apartment.h"

using namespace std;

Apartment::Apartment(bool washer, int story):Residence(4,4,washer){
  m_story = story;
}

int Apartment::PropertyValue(){
  if(HasWasher() == true){
    return NumRooms() * 10000 + 100;
  }
  else{
    return NumRooms() * 10000;
  }}

ostream &operator<<(ostream &out, const Apartment& apt)
{
    // Fill the rest of this method in
    // Use this one as a model for the other << operators
  out << "Number of Rooms: " << apt.NumRooms() << '\n';
  out << "Number of Walls: " << apt.NumWalls() <<'\n';
  out << "Washer: " << apt.HasWasher()<<'\n';
  out << "Number of Windows: " << apt.NumWindows()<<'\n';
  out << "Property Value: "<< apt.PropertyValue();

    return out;
}
