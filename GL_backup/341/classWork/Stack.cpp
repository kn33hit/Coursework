#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"
#include <iostream>
using namespace std;

template <class T>
Stack<T>::Stack(const int num)
{
  top = -1;
  maxelem = num;
  s = new T[maxelem];
}

template <class T>
void Stack<T>::push(const T t)
{
  if (top == maxelem) return;
  s[++top] = t;
}

template <class T>
T Stack<T>::pop()
{
  if (top == -1) { return -1; }
  return s[--top];
}

template <class T>
T Stack<T>::peek()
{
  if (top == -1) { return -1; }
  return s[top];
}

template <class T>
void Stack<T>::display()
{
  if (top == -1) { cout << "(empty)\n";  return; }
  for (int t=0; t <= top; t++) cout << s[t] << " ";
  cout << "\n";
}

template <class T>
T Stack<T>::empty() {  return top == -1;  }

#endif
