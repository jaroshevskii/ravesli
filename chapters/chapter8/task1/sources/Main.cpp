#include "Point.h"
#include <iostream>

int main() {
  const Point firstPoint;
  firstPoint.print();

  const Point secondPoint(2.0, 5.0);
  secondPoint.print();

  std::cout << "Distance between two points: "
            << distanceFrom(firstPoint, secondPoint) << '\n';
  return 0;
}