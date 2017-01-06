/**************************************************************************
 ** File: Fraction.h
 ** Project: CMSC Project 3, Spring 2014
 ** Author: Neh Patel 
 ** Date: 4/9/2014
 ** Section: 08 
 ** E-mail: npatel10@umbc.edu 
 ** 
 **    This file contains the fraction class definitions and also the extra
 **    non-member class functions that will be used to complete project 3
 **    The description of project 3 is in the cpp file 
 **
 *************************************************************************/

#ifndef FRACTION_H
#define FRACTION_H 
#include <iostream>
using namespace std;

class Fraction{
 public:
/***********************************************************************
  Fraction 
     a default constructor that sets whole and numerator values to 0, and the 
     denominator value to 1
  No PRE or POST conditions
***********************************************************************/
  Fraction();

/*********************************************************************
  ~Fraction 
     a destructor which is not really used I have not used in the cpp file
   No PRE POST conditions for it 
*******************************************************************/
  ~Fraction();
  
/*********************************************************************
  Fraction
     a constructor which takes in the numerator and the denominator and 
     sets the denominator and the numerator properly 
  NO PRE conditions required
  POST:
     the denominator cannot be a zer or the program exits 
  *******************************************************************/
  Fraction(int num, int den);
  
  /*********************************************************************
  Fraction
     a constructor which takes in the whole, numerator, and denominator and
     sets them all properly
  NO PRE conditions required
  POST:
     the denominator cannot be a zero or the program exits
  *******************************************************************/
  Fraction(int whole, int num, int den);
  
  /*********************************************************************
  GetWhole
     an accessro method that allows you to access the whole number value 
  NO PRE or POST conditions required
  returns an int 
  *******************************************************************/
  int GetWhole();
  
  /*********************************************************************
  GetNume
     an accessro method that allows you to access the numerator number value
  NO PRE or POST conditions required
  returns an int 
  *******************************************************************/
  int GetNume();
  
 /*********************************************************************
  GetDen
     an accessro method that allows you to access the denominator number value
  NO PRE or POST conditions required
  rturns an int 
  *******************************************************************/
  int GetDen();
  
  /*********************************************************************
  GetImpNum
     an accessro method that allows you to access the imporper numerator 
     number value
  NO PRE or POST conditions required
  rturns an int
  *******************************************************************/
  int GetImpNum();
  
  /*********************************************************************
  GetImpDen
     an accessro method that allows you to access the improper
     denominator number value
  NO PRE or POST conditions required
  rturns an int
  *******************************************************************/
  int GetImpDen();
  
  /*********************************************************************
  SetWhole
     an mutator method that allows you to mutate the whole number value
  NO PRE or POST conditions required
  *******************************************************************/
  void SetWhole(int i);
  
  /*********************************************************************
  SetNume
     an mutator method that allows you to mutate the numerator value
  NO PRE or POST conditions required
  *******************************************************************/
  void SetNume(int i);
  
  /*********************************************************************
  SetDen
     an mutator method that allows you to mutate the denominator value
  NO PRE or POST conditions required
  *******************************************************************/
  void SetDen(int i);
  
  /*********************************************************************
  SetImpNum
     an mutator method that allows you to mutate the improper numerator value
  NO PRE or POST conditions required
  *******************************************************************/
  void SetImpNum(int i);
  
  /*********************************************************************
  SetImpDen
     an mutator method that allows you to mutate the improper denominator value
  NO PRE or POST conditions required
  *******************************************************************/
  void SetImpDen(int i);
  
  /*********************************************************************
  operator+ 
     operator overloading method + 
     allows to add the two fractions 
  PRE 
     denominator cannot be a zero 
     a fraction must be passed in
  POST 
     returns a new fraction which is the added fraction 
     value of the two fractions 
  *******************************************************************/
  Fraction operator+(Fraction frac2);
  
  /*********************************************************************
  operator-
     operator overloading method -
     allows to subtract the fraction from another
  PRE
     denominator cannot be a zero
     a fraction must be passed in
  POST
     returns a new fraction which is the sybtracted fraction 
     value of the two fractions
  *******************************************************************/
  Fraction operator-(Fraction frac2);
  
  /*********************************************************************
  operator/
     operator overloading method /
     allows to divide the fraction from another
  PRE
     denominator cannot be a zero
     a fraction must be passed in
  POST
     returns a new fraction which is the divided fraction
     value of the two fractions
  *******************************************************************/
  Fraction operator/(Fraction frac2);

  /****************************************************************** 
  operator*
     operator overloading method *
     allows to multiply the fraction from another
  PRE
     denominator cannot be a zero
     a fraction must be passed in
  POST
     returns a new fraction which is the multiplied fraction
     value of the two fractions
  *******************************************************************/
  Fraction operator*(Fraction frac2);

 private:
  int m_whole;
  int m_numerator;
  int m_denominator;
  int m_impNum;   // improper fraction numerator
  int m_impDen;  //improper fraction denominator
}; 

// OTHER NON-MEMBER FUNCTIONS 
/*******************************************************************
 operator<<
     operator overloading method <<
     allows to output the fraction in the format of 0&0/1 
  PRE
     denominator cannot be a zero
     a fraction must be passed in
  POST
     outputs a fraction
  *******************************************************************/
ostream& operator<<(ostream& sout, Fraction& frac);

/*******************************************************************
 Normalize
     this fucntion helps "normalize" the fraction into a more simpler 
     fraction 
     The fractions should meet the following criteria to be considered 
     "normalized":
     1) denominator > 0
     2) numerator and whole number signs shold be the same (+/-) 
     3) |numerator| < denominator 
     4) fraction part reduced to lowest form
     5) If numerator is 0. then denomminator is 1 
  PRE
     denominator cannot be a zero
     a fraction must be passed in
  POST
     outputs a fraction
*******************************************************************/
Fraction Normalize(Fraction frac);

/*******************************************************************
 gcd
     this method helps to calculate the greates common denominator 
     using the fractions numerator and denominator 
  PRE
     numerator must be passed in 
  POST
     returns a gcd 
*******************************************************************/
int gcd(int i, int j);

/*******************************************************************
 ImproperToMixed 
     Most of our fractions are used as improper fractions to 
     do the calculations, so this method takes in an improper fraction and
     makes it into its mixed fraction format 
  PRE
     denominator cannot be a zero
     a fraction must be passed in
  POST
     returns a fractin with its mixed fraction values modified if needed
*******************************************************************/
Fraction ImproperToMixed(Fraction frac);

#endif 
