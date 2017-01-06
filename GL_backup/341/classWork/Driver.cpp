/*
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main(){
  Rectangle a;
  cout << "a should (1,1)" << endl;
  cout << "b should be (3,4)" << endl;
  Rectangle b(3,4);
  
  //CHECKING AREA 
  int area = b.GetArea();
  cout << "Area of b is: " << area << endl;
  
  int peri= a.GetPerimeter();
  cout << "Perimeter of a is: " << peri << endl;

  int len = b.GetLength();
  cout << " length of b is " << len << endl;
  
  int wid = a.GetWidth();
  cout << "widht of a is " << wid << endl;

  int dig = b.GetDiagonal();
  cout << dig << endl;
  
  bool one = a.IsSquare();
  cout << "Is a a square? " << one << endl;

  bool two = b.IsSquare();
  cout << "Is b a square? " << two << endl;

  a = Rectangle(5,90);
  cout << "len of a is " << a.GetLength() << endl;
  cout << "width of a is " << a.GetWidth() << endl;

}
*/

#include "Stack.h"

#include <iostream>
using namespace std;

int main()
{

  Stack <int> intStack(100);
  intStack.push(23);
  cout << intStack << endl;

  Stack <char> test1 = Stack<char>(40);
  test1.push('L');
  cout << test1 << endl;

  Stack <double> * test2 = new Stack<double>(40);
  test2->push(123.23);
  cout << *test2 << endl;
}
