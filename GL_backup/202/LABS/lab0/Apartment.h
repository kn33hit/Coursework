#ifndef APARTMENT_H
#define APARTMENT_H

#include <ostream>
#include "Residence.h"

class Apartment : public Residence // Inherit publicly from Residence
{
    // Data members:
    // The story the apartment is on
 private:
  int m_story;
    // Public methods:
    // Apartment(bool washer, int story) - call Residence constructor with
 public:
  Apartment(bool washer, int story);
  //     4, 4, whether there is a washer, initialize story data member
    // Override these methods:
    // PropertyValue() - Add 100 to the original property value if there is
    //     a washer in the apartment.
  int PropertyValue();
    // Make operator << a friend
  std::ostream &operator<<(std::ostream &out);
};



#endif
