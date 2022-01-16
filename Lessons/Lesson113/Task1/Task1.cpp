#include <iostream>

class Numbers {
public:
  int number1;
  int number2;

  void set(int n1, int n2) {
    number1 = n1;
    number2 = n2;
  }

  void print() {
    std::cout << "Numbers(" << number1 << ", " << number2 << ")\n";
  }
};

int main() {
  Numbers n1;
  n1.set(3, 3); // Initialize object n1 with values ​​3 and 3.

  Numbers n2{4, 4}; // Initialize object n2 with values ​​4 and 4.

  // Print object n1 and n2.
  n1.print();
  n2.print();
  return 0;
}