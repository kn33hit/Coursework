#include <iostream>
#include "Dog.h"
#include <string>
using namespace std;

int main(){
  


  cout << "Creating Dogs.." << endl;
  Dog dog1("grep", 2006);
  Dog dog2("Dr.Pepper", 2004);
  
  cout << "Dog1's name is:" << dog1.GetName() << endl;
  cout << "Dog2's name is:" << dog2.GetName() << endl;  
  
  cout << "Dog1's age is:" << dog1.GetAge(2014) << endl;
  
  dog2.SetOwner("Red Bull");
  cout << "Setting Dog2's owner to : " << dog2.GetOwner() << endl;

  cout << "Dog2's owner is " << dog2.GetOwner() << endl;

  int i = 0;
  while(i < 5){
    dog2.Abuse();
    cout << "Abusing Dog2";
    i++;  
  }

  dog1.Pat();
  cout << "Dog2 is " << dog2.GetHappiness() << endl;
  cout << "Dog1 is " << dog1.GetHappiness() << endl;
  while(i> -2){
    dog2.Pat();
    i--;
    cout << "Patting Dog2" << endl;
  }

  cout << "Dog2 is " << dog2.GetHappiness() << endl;
  cout << "Dog1 says ";
  dog1.Talk();



}
