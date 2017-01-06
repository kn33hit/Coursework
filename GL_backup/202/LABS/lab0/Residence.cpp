#include "Residence.h"

using namespace std;

Residence::Residence(int rooms, int walls, bool washer)
// Initializer list goes here
{
  m_rooms =rooms;
  m_walls = walls;
  m_washer = washer;
}

void Residence::SetRooms(int room){
  m_rooms = room;
}
void Residence::SetWalls(int wall){
  m_walls = wall;
}
void Residence::SetWasher(bool washer){
  m_washer = washer;
}
int Residence::PropertyValue() const
{
    // Fill this in...
  return m_rooms * 10000;
}

int Residence::NumWindows() const
{
    // Fill this in...
  return m_walls * 2;
}

bool Residence::HasWasher() const
{
    // Fill this in...
  return m_washer;
}

int Residence::NumRooms() const
{
    // Fill this in...
  return m_rooms;
}

int Residence::NumWalls() const
{
    // Fill this in...
  return m_walls;
}

ostream &operator<<(ostream &out, const Residence &obj)
{
    // Fill the rest of this method in
    // Use this one as a model for the other << operators
  out << "Number of Rooms: " << obj.NumRooms() << '\n';
  out << "Number of Walls: " << obj.NumWalls() <<'\n';
  out << "Washer: " << obj.HasWasher()<<'\n';
  out << "Number of Windows: " << obj.NumWindows()<<'\n';
  out << "Property Value: "<< obj.PropertyValue();

    return out;
}
