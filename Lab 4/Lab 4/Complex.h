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
   Complex(const Complex &other);
   ~Complex();
   std::string ToString() const;

   double GetReal() const;
   void SetReal(double real);

   double GetImaginary() const;
   void SetImaginary(double imaginary);

   double AbsoluteValue() const;
   bool Equals(const Complex &other) const;

   Complex Conjugate() const;
   Complex Multiply(const Complex &other) const;
   
   Complex &operator=(const Complex &rhs);
};

#endif