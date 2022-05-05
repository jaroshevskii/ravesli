#include <iostream>

class Numbers {
private:
  int myFirst{};
  int mySecond{};

public:
  Numbers() = default;

  Numbers(int first, int second) : myFirst{first}, mySecond{second} {}

  void set(int first, int second) {
    myFirst = first;
    mySecond = second;
  }

  void print() const {
    std::cout << "Numbers(" << myFirst << ", " << mySecond << ")\n";
  }
};

int main() {
  auto n1 = Numbers{};
  
  // Initialize object n1 with values ​​3 and 3.
  n1.set(3, 3);
  
  // Initialize object n2 with values ​​4 and 4.
  const auto n2 = Numbers{4, 4};

  n1.print();
  n2.print();
  return 0;
}