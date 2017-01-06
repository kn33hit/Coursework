#include <iostream>
#include "Tent.h"
#include "House.h"
#include "Apartment.h"

using namespace std;

int main()
{
    cout << "House:" << endl;
    // Make a House object
    House house1;

    // cout the House object
    cout << house1;

    cout << endl << "Apartment:" << endl;
    // Make an Apartment object
    Apartment apt1(false,2);
    cout << apt1;

    // cout the Apartment object

    cout << endl << "Tent:" << endl;
    // Make a Tent object
    Tent tent1;
    cout << tent1;

    // cout the Tent object
    
    return 0;
}
