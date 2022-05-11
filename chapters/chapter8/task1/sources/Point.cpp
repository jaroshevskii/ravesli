#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point(double a, double b) : myA{a}, myB{b} {}

/// Prints a point.
void Point::print() const {
  std::cout << "Point{" << myA << ", " << myB << "}\n";
}

/// Returns the distance between two points.
double distanceFrom(const Point &first, const Point &second) {
  return std::sqrt((first.myA - second.myA) * (first.myA - second.myA) +
                   (first.myB - second.myB) * (first.myB - second.myB));
}
