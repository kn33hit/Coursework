#include "Complex.h"

// Complex class constructor
Complex::Complex(int real, int imaginary):m_real(real),m_imaginary(imaginary)
{
 
}

// Accessor that returns real part of complex number
int Complex::GetReal() const
{
  return m_real;
}

// Accessor that returns imaginary part of complex number
int Complex::GetImaginary() const
{
  return m_imaginary;
}

// Start writing your code here ....


 // Overloaded + operator as member function
const Complex Complex::operator+ (const Complex& rhs) const
{
  Complex c;
  c.m_imaginary = m_imaginary + rhs.m_imaginary; 
  c.m_real = m_real + rhs.m_real;
  return c;
}
      // Overloaded unary minus operator as member function 
const Complex Complex::operator-() const
{
  Complex c;
  c.m_imaginary = -m_imaginary;
  c.m_real = -m_real;
  return c;
}

ostream& operator<<(ostream& sout, const Complex& number)
{
  if(number.GetImaginary() < 0){
    sout << number.GetReal()  << number.GetImaginary() << "i" << endl;
  }
  else{
    sout << number.GetReal() << " + " << number.GetImaginary() << "i" << endl;
  }

  return sout;
}
