#include <iostream>
#include "Complex.h"

#include <string>

using namespace std;

int main(int argc, char* argv[]) {
   Complex complex1;
   const Complex complex2(5, -12);
   
   cout << "Complex 2: " << complex2.ToString() << endl;
  
   complex1.SetReal(4);
   complex1.SetImaginary(-12);
   
   cout << "Complex 1 Real Number: " << complex1.GetReal() << endl;
   cout << "Complex 1 Imaginary Number: " << complex1.GetImaginary() << endl;
   cout << "Complex 2 Absolute Value: " << complex2.AbsoluteValue() << endl;
   cout << "Complex 1 x Complex 2 : " << complex1.Multiply(complex2).ToString() << endl;

}


