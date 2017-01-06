#ifndef RESIDENCE_H
#define RESIDENCE_H

#include <ostream>

class Residence
{
    // Data members:
    // Number of rooms
 
    // Number of walls // Whether or not there is a washer (this is a boolean)
     // Protected Methods:

    // HasWasher() - return whether or not there is a wa
  // NumRooms() - return number of rooms
  // NumWalls() - return number of wall

    // Public methods:
    // Residence(int rooms, int walls, bool washer) - initialize data members
  // PropertyValue() - return property value (number of rooms * 100
  // NumWindows() - return number of windows (number of walls * 2)
   

  // Make the << operator a friend

    // Let's pretend we've done all this business already...
public:
    Residence(int rooms, int walls, bool washer);
    int PropertyValue() const;
    int NumWindows() const;
    void SetRooms(int r);
    void SetWalls(int r);
    void SetWasher(bool w);
    friend std::ostream &operator<<(std::ostream &out, const Residence &obj);

protected:
    bool HasWasher() const;
    int NumRooms() const;
    int NumWalls() const;
    
private:
    int m_rooms;
    int m_walls;
    bool m_washer;
};

std::ostream &operator<<(std::ostream &out, const Residence &obj);

#endif
