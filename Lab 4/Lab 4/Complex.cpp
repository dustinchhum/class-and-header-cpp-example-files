#include <iostream>;
#include "Complex.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <string>
#include <sstream>

using namespace std;

Complex::Complex() : mReal(0), mImaginary(0){
   cout << "Default constuct " << ToString() << endl;
}

Complex::Complex(double real, double imaginary) : mReal(real), mImaginary(imaginary){
   cout << "Construct " << ToString() << endl;
}

Complex::Complex(const Complex &other) : mReal(other.mReal), mImaginary(other.mImaginary) {
   cout << "Copy construct " << ToString() << endl;
}

Complex::~Complex() {
   cout << "Destruct " << ToString() << endl;
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

double Complex::GetReal() const {
   return mReal;
}

void Complex::SetReal(double real) {
   string before = ToString();
   mReal = real;
   string after = ToString();
   cout << "Mutate " << before << " to " << after << endl;
}

double Complex::GetImaginary() const {
   return mImaginary;
}

void Complex::SetImaginary(double imaginary) {
   string before = ToString();
   mImaginary = imaginary;
   string after = ToString();
   cout << "Mutate " << before << " to " << after << endl;
}

double Complex::AbsoluteValue() const {
   cout << "Absolute Value: ";
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
   cout << "Conjugate: ";
   return Complex(mReal, mImaginary * -1);
}

Complex Complex::Multiply(const Complex &other) const {
   cout << "Multiply: " << endl;
   return Complex(mReal * other.GetReal() - mImaginary * other.GetImaginary(), mReal * other.GetReal() + mImaginary * other.GetImaginary());
}

Complex& Complex::operator=(const Complex &rhs){
   string before = ToString();
   mReal = rhs.mReal;
   mImaginary = rhs.mImaginary;
   string after = ToString();
   cout << "Operator= " << before << " ==> " << after << endl;
   return *this;
}



