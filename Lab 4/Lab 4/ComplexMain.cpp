#include "Complex.h"
#include <iostream>

using namespace std;

void CompareComplex(Complex first, const Complex& second);

int main() {
   Complex c1(1.5, 2);
   Complex c2(-3, 4);
   Complex *cPtr;

   cout << endl;

   if (true) {
      Complex c3(c2);
      cPtr = new Complex(5, 5);
      cout << "The conjugate of " << c3.ToString() << " is " <<
         c3.Conjugate().ToString() << endl;
   }

   cout << endl;
   Complex copy1 = c2;
   copy1.SetReal(10);
   Complex copy2(copy1);

   cout << endl;
   copy1 = c2;
   copy1 = c2.Conjugate();

   cout << endl;
   Complex c3(-3, -4);
   CompareComplex(c3, copy1);
   cout << endl;

}

void CompareComplex(Complex first, const Complex& second) {
   cout << first.Equals(second) << endl;
}
#if 0

Construct 1.5 + 2i // LINE 9
Construct - 3 + 4i // LINE 10

Copy construct - 3 + 4i // LINE 16
Construct 5 + 5i // LINE 17
Conjugate: Construct - 3 - 4i // Conjugate()
The conjugate of - 3 + 4i is - 3 - 4i // LINE 18 - 19
Destruct - 3 - 4i // ~Complex()
Destruct - 3 + 4i // ~Complex()

Copy construct - 3 + 4i // LINE 23
Mutate - 3 + 4i to 10 + 4i // LINE 24
Copy construct 10 + 4i // ?? DO TMMR

Operator = 10 + 4i == > -3 + 4i
Conjugate: Construct - 3 - 4i
Operator = -3 + 4i == > -3 - 4i
Destruct - 3 - 4i

Construct - 3 - 4i
Copy construct - 3 - 4i
1
Destruct - 3 - 4i

Destruct - 3 - 4i
Destruct 10 + 4i
Destruct - 3 - 4i
Destruct - 3 + 4i
Destruct 1.5 + 2i
                   Press any key to continue . . .
#endif // 0
