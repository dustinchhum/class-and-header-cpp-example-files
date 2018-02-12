#include "Complex.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <string>
#include <sstream>

using namespace std;

Complex::Complex() : mReal(0), mImaginary(0){
}

Complex::Complex(double real, double imaginary) : mReal(real), mImaginary(imaginary){
}

double Complex::GetReal() const {
   return mReal;
}

void Complex::SetReal(double real) {
   mReal = real;
}

double Complex::GetImaginary() const {
   return mImaginary;
}

void Complex::SetImaginary(double imaginary) {
   mImaginary = imaginary;
}

double Complex::AbsoluteValue() const {
   return sqrt(mReal * mReal + mImaginary * mImaginary);
}

bool Complex::Equals(const Complex &other) const {
   bool isEqual = true;
   if (mReal != other.mReal) {
      isEqual = false;
   }
   if (mImaginary != other.mImaginary) {
      isEqual = false;
   }
   return isEqual;
}

Complex Complex::Conjugate() const {
   Complex newComplex;
   newComplex.SetReal(mReal);
   newComplex.SetImaginary(mImaginary * -1);
   return newComplex;
}

Complex Complex::Multiply(const Complex &other) const {
   Complex newComplex;
   newComplex.SetReal(mReal * other.GetReal() - mImaginary * other.GetImaginary());
   newComplex.SetImaginary(mReal * other.GetReal() + mImaginary * other.GetImaginary());
   return newComplex;
}

string Complex::ToString() const {
   ostringstream format;
   if (mImaginary > 0) {
      format << mReal << '+' << mImaginary << "i";
   }
   else {
      format << mReal << mImaginary << "i";
   }
   return format.str();
}




