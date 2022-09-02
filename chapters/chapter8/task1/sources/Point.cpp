#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point(double a, double b) : a(a), b(b) {}

void Point::print() const { std::cout << "Point(" << a << ", " << b << ")\n"; }

double distanceFrom(const Point &first, const Point &second) {
  return std::sqrt((first.a - second.a) * (first.a - second.a) +
                   (first.b - second.b) * (first.b - second.b));
}
