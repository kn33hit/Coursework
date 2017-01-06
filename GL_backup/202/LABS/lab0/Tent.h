#ifndef TENT_H
#define TENT_H

#include <ostream>
#include "Residence.h"

class Tent : public Residence  // Inherit publicly from Residence
{
    // Public methods:
    // Tent() - call Residence constructor with 1, 2, false as parameters
 public:
  Tent();  
  // Override these methods:
    // PropertyValue() - return 0
  int PropertyValue();
  int NumWindows();
  // NumWindows() - return 0
    // Make the << operator a friend
};

std::ostream &operator<<(std::ostream &out, const Tent &obj);

#endif
