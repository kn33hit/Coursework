#include <iostream>
#include "IntArray.h"

using namespace std;

int main()
{
    // Create IntArray objects and call methods here...
  IntArray yo;
  IntArray yo3(-324,3);
  IntArray yo2(232138,213);
  IntArray yo5(yo3);
  IntArray yo4(0);
  if(yo == yo3) cout << "truu";
  if(yo != yo5) cout << "truu";
  yo3 = yo4 + yo;
  yo4.SetItem(-4,56);
  yo4.Insert(-5,-4);
  yo4.Del(-5);
  yo4.Get(6);
  yo5.Get(-34);
  yo4.Clear();

  IntArray one(5,5);
  cout << "Array One" << endl;
  for(int i = 0; i < 5; i++){
    cout << one.Get(i) << " ";}
  IntArray two(one);
  cout << endl;
  cout << "Array Two" << endl;
  for(int i = 0; i < 5; i++){
    cout << one.Get(i) << " ";}

  one.SetItem(0,3);
  one.SetItem(1,3);
one.SetItem(2,3);
one.SetItem(3,3);
 one.SetItem(4,3);
 cout << endl;
 cout << "Array One" << endl;
  for(int i = 0; i < 5; i++){
    cout << one.Get(i) << " ";}

 cout << endl;
  cout << "Array Two" << endl;
  for(int i = 0; i < 5; i++){
    cout << two.Get(i) << " ";}


   // Print out the number of errors/edge cases found
    cout << endl << endl << IntArray::GetProgress() << endl;
    
    return 0;
}
