//Author: Man Wa Mo
#include <iostream>

using namespace std;

int sumNum(int num)
{
  int temp = 0;
  int total = 0;
  while(num >= temp)
    {
      total += temp;
      temp++;
    }
  return total;
}

int factorial(int num)
{
  int total = 1;
  for(int temp = 1; temp <= num; temp++)
    {
      total *= temp;
    }
  return total;
}

int main()
{
  char name[80];
  char num[80];
  int sum;
  int factSum;
  cout << "Hello. What is  your name? ";
  cin >> name;
  cout << "Hi ";
  cout << name;
  cout << ", please enter an integer: ";
  cin >> num;
  int numUse = num[0]-'0';
  sum = sumNum(numUse);
  cout << "Sum: ";
  cout << sum << endl;
  factSum = factorial(numUse);
  cout << "Factorial: ";
  cout << factSum<< endl;
  return 0;
}
