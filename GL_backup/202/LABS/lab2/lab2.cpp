#include <iostream>
using namespace std;


int main() 
{
  int number;
  char name[80];
  int total = 0;

  cout << "Enter a number" << endl;
  cin >> number;
  cout << "Now, enter a name" << endl;
  cin >> name;
  cout << "Your name is " << name << endl;

  int x = 0;
  int factorial = 1;

  while(x <= number){
    total += x;
    x++;
      }
  cout << "total = " << total << endl;

  for(int i = number; i > 1; i--) {
   
    factorial = factorial * i;

  }
  cout << "factorial total is " << factorial << endl;


}
