#include "fraction.h"
#include <iostream>
using namespace std;

fraction::frac(){
  m_numerator = 1;
  m_denominator = 1;
}

fraction::frac(int numerator, int denominator){
  if(denominator != 0){
    m_numerator = numerator;
    m_denominator = denominator;
  } else{
    cout << "The denominator cannot be a zero" << endl;
}

void fraction::Output(){
  cout << m_numerator << "/" << m_denominator << endl;
}

void fraction::Reciprocal(){
  int temp;
  int numerator = m_numerator;
  int denominator = m_denominator;
  temp = numerator;
  numerator = denominator;
  denominator = temp;
  frac fracRec(numerator,denominator);
  return fracRec;
}
,m_numerator);
  return fracRec;
}
