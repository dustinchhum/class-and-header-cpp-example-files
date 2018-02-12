#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <string>

class Complex {
private:
   double mReal;
   double mImaginary;

public:
   Complex();
   Complex(double real, double imaginary);
   std::string ToString() const;

   double GetReal() const;
   void SetReal(double real);
   
   double GetImaginary() const;
   void SetImaginary(double imaginary);
   
   double AbsoluteValue() const;
   bool Equals(const Complex &other) const;
   
   Complex Conjugate() const;
   Complex Multiply(const Complex &other) const;
};

#endif