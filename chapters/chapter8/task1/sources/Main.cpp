#include "Point.h"
#include <iostream>

int main() {
  const auto first = Point{};
  const auto second = Point{2.0, 5.0};

  first.print();
  second.print();
  std::cout << "Distance between two points: " << distanceFrom(first, second)
            << '\n';
  return 0;
}