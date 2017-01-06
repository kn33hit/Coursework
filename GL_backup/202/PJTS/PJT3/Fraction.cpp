/**************************************************************************
 ** File: Fraction.cpp
 ** Project: CMSC Project 3, Spring 2014
 ** Author: Neh Patel
 ** Date: 4/9/2014
 ** Section: 08
 ** E-mail: npatel10@umbc.edu
 **
 **    This file contains the fraction class implementations and also the extra
 **    non-member class functions that will be used to complete project 3
 **    This project is based upon a fraction desk calculator which takes 
 **    fractions and uses the four basic arithmetic calculations using 
 **    the fractions entered on a prefic form. Also this project 
 **    implements and uses operaotr overloading on +,-,/,*, and  << 
 **    operators 
 ** 
 *************************************************************************/


#include "Fraction.h"
#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
// DEFAULT CONSTRUCTOR 
Fraction::Fraction(){
  m_whole = 0;
  m_numerator = 0;
  m_denominator = 1;
  m_impNum = 0;
  m_impDen = 1;
}


// DESTRUCTOR 
Fraction::~Fraction(){
}


// 2 MORE CONSTRUCTORS 
Fraction::Fraction(int num, int den){
  if(den == 0){
    cout << "Denominator cannot be zero" << endl;
    exit(1);
  }
  m_whole = 0;
  m_numerator = num;
  m_denominator = den;
  m_impNum = num;
  m_impDen = den;
}

Fraction::Fraction(int whole, int num, int den){
   if(den == 0){
     cout << "Denominator cannot be a zero" << endl; 
     exit(1);
  }
  m_whole = whole;
  m_numerator = num;
  m_denominator = den;
  m_impNum = whole * den + num;
  m_impDen = den;
}


// ACCESSORS 
int Fraction::GetWhole(){
  return m_whole;
}
int Fraction::GetNume(){
  return m_numerator;
}
int Fraction::GetDen(){
  return m_denominator;
}
int Fraction::GetImpNum(){
  return m_impNum;
}
int Fraction::GetImpDen(){
  return m_impDen;
}


// MUTATORS 
void Fraction::SetWhole(int i){
  m_whole = i;
}
void Fraction::SetNume(int i){
  m_numerator = i;
}
void Fraction::SetDen(int i){
  m_denominator = i;
}
void Fraction::SetImpNum(int i){
  m_impNum = i;
}
void Fraction::SetImpDen(int i){
  m_impDen = i;
}


// OPERATOR OVERLOADING 
Fraction Fraction::operator+(Fraction frac2){
  Fraction fraction;
  
  // a/b + c/d = finalNum =(a*d + b*c)/ finalDen =(b*d)
  // first, a * d + b * c 
  fraction.SetImpNum((GetImpDen() * frac2.GetImpNum()) +(GetImpNum() * frac2.GetImpDen())); 
  
  fraction.SetImpDen(GetImpDen() * frac2.GetImpDen()); // b * d  
  
  // normalizing 
  fraction = ImproperToMixed(fraction);
  
  fraction = Normalize(fraction);
  
  return fraction;
}

Fraction Fraction::operator-(Fraction frac2){
  Fraction fraction;
  
  // a/b - c/d = finalNum =(a*d - b*c)/ finalDen =(b*d)
  // first, a* d - b * c
  fraction.SetImpNum((GetImpDen() * frac2.GetImpNum()) - (GetImpNum() * frac2.GetImpDen())); 
  // b * d
  fraction.SetImpDen(GetImpDen() * frac2.GetImpDen()); // numerator
  
  // normalizing   
  fraction = ImproperToMixed(fraction);
  
  fraction = Normalize(fraction);
  
  return fraction;
}

Fraction Fraction::operator/(Fraction frac2){
  Fraction fraction;
  
  // a/b / c/d = frac1 * reciprocal of frac2 
  // num(a*d) / den (b*c)
  fraction.SetImpNum(GetImpNum() * frac2.GetDen()); // (a * d)
  fraction.SetImpDen(GetImpDen() * frac2.GetImpNum()); // (b *c) 
  
  fraction = ImproperToMixed(fraction);
  
  fraction = Normalize(fraction); 
  
  return fraction;
}

Fraction Fraction::operator*(Fraction frac2){
  Fraction fraction;
  
  // a/b * c/d = num(a*c) / den(b*d)
  fraction.SetImpNum(GetImpNum() * frac2.GetImpNum());  // a * c 
  fraction.SetImpDen(GetImpDen() * frac2.GetImpDen());  // b * d
  
  fraction = ImproperToMixed(fraction);
  
  fraction = Normalize(fraction);
  
  return fraction;
}


// NON-MEMBER FUNCTIONS 
ostream& operator<<(ostream& sout,Fraction& frac2)
{
  // printting out fraction in 0&0/1 format
  sout << frac2.GetWhole() << "&" << frac2.GetNume() << "/" <<	\
    frac2.GetDen() << endl;
  return sout;
}

Fraction ImproperToMixed(Fraction frac){
  // TURN IT INTO MIXED FORMAT
  // numerator
  frac.SetWhole(int(frac.GetImpNum()/frac.GetImpDen()));
  // denominator
  frac.SetDen(frac.GetImpDen());
  // whole number
  frac.SetNume(frac.GetImpNum() % frac.GetImpDen());
  
  return frac;
}

Fraction Normalize(Fraction frac){  
  // time to normalize it 
  // I could've made a function to turn the fraction from improper to mixed
  // not good design but i like seeing things in one block than several 

  // CONDITION 1  ( denominator > 0 )
  if(frac.GetDen() <  0){
    frac.SetDen(abs(frac.GetDen()));
  }

  // CONDITION 2  ( sign(num) == sign(whole) 0 matches any sign 
  // whole is positive and numerator is negative 
  if(frac.GetWhole() > 0 && frac.GetNume() < 0){
    // set numerator as its positive value by using absolute value method
    frac.SetNume(abs(frac.GetNume()));
  }
  
  // whole is negative and numerator is positive 
  if(frac.GetWhole() < 0 && frac.GetNume() > 0){
    // set numerator as its negative value by subtracting twice as much 
    frac.SetNume(frac.GetNume() - (frac.GetNume() * 2));
  }  // this way if zero was either numeraotr or whole it wouldnt care about it

  // CONDITION 3  ( abs(numerator) < denominator )
  if(abs(frac.GetNume()) > frac.GetDen()){
    // do something here, I was really confused of what was to be done here 
  }
  
  // CONDITION 4  fractional part is reduced to lowest terms 
    frac.SetNume(frac.GetNume() / gcd(frac.GetNume(),frac.GetDen()));
    frac.SetDen(frac.GetDen() / gcd(frac.GetNume(),frac.GetDen()));

  // CONDITION 5  if (numerator = 0) denominator set to 1
  if(frac.GetNume() == 0){
    frac.SetDen(1);
  }

  // returning the final result  
  return frac;
}

int gcd(int num1, int num2){
  int r;

  while(num1 != 0){
    r = num2 % num1;
    num2 = num1;
    num1 = r;
  }
  
  // after the while loop num2 is the gcd 
  return num2;
}
