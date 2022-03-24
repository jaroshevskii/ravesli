#include <iostream>

class Numbers {
private:
  int myFirst;
  int mySecond;

public:
  Numbers() : myFirst{}, mySecond{} {}

  Numbers(int first, int second) : myFirst{first}, mySecond{second} {}

  ~Numbers() {}

  void set(int first, int second) {
    myFirst = first;
    mySecond = second;
  }

  void print() {
    std::cout << "Numbers(" << myFirst << ", " << mySecond << ")\n";
  }
};

int main() {
  Numbers n1;
  n1.set(3, 3); // Initialize object n1 with values ​​3 and 3.

  Numbers n2{4, 4}; // Initialize object n2 with values ​​4 and 4.

  n1.print();
  n2.print();
  return 0;
}