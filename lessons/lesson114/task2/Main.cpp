#include <iostream>

class Numbers {
private:
  double myA = 0.0;
  double myB = 0.0;
  double myC = 0.0;

public:
  Numbers() {}

  ~Numbers() {}

  void setValues(double a, double b, double c) {
    myA = a;
    myB = b;
    myC = c;
  }

  void print() {
    std::cout << '<' << myA << ", " << myB << ", " << myC << ">\n";
  }

  bool isEqual(const Numbers &numbers) {
    return myA == numbers.myA && myB == numbers.myB && myC == numbers.myC;
  }
};

int main() {
  Numbers point1;
  point1.setValues(3.0, 4.0, 5.0);

  Numbers point2;
  point2.setValues(3.0, 4.0, 5.0);

  if (point1.isEqual(point2)) {
    std::cout << "point1 and point2 are same\n";
  } else {
    std::cout << "point1 and point2 are different\n";
  }

  Numbers point3;
  point3.setValues(7.0, 8.0, 9.0);

  if (point1.isEqual(point3)) {
    std::cout << "point1 and point2 are same\n";
  } else {
    std::cout << "point1 and point2 are different\n";
  }
  return 0;
}