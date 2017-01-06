#ifndef HOUSE_H
#define HOUSE_H

#include "Residence.h"

class House : public Residence // Inherit publicly from Residence
{
    // House() - calls Residence constructor with 4, 4, true as parameters
 public:
  
  House();
};

#endif
