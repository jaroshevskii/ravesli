#include <iostream>

class Numbers {
private:
  double myA{};
  double myB{};
  double myC{};

public:
  Numbers() = default;

  void setValues(double a, double b, double c) {
    myA = a;
    myB = b;
    myC = c;
  }

  void print() const {
    std::cout << '<' << myA << ", " << myB << ", " << myC << ">\n";
  }

  bool isEqual(const Numbers &numbers) const {
    return myA == numbers.myA && myB == numbers.myB && myC == numbers.myC;
  }
};

int main() {
  auto point1 = Numbers{};
  point1.setValues(3.0, 4.0, 5.0);

  auto point2 = Numbers{};
  point2.setValues(3.0, 4.0, 5.0);

  if (point1.isEqual(point2)) {
    std::cout << "point1 and point2 are same.\n";
  } else {
    std::cout << "point1 and point2 are different.\n";
  }

  auto point3 = Numbers{};
  point3.setValues(7.0, 8.0, 9.0);

  if (point1.isEqual(point3)) {
    std::cout << "point1 and point2 are same.\n";
  } else {
    std::cout << "point1 and point2 are different.\n";
  }
  return 0;
}