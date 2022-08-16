#include "Vector3D.h"

#include <iostream>

Vector3D::Vector3D(double x, double y, double z) : x{x}, y{y}, z{z} {}

auto Vector3D::print() const -> void {
  std::cout << "Vector{" << x << ", " << y << ", " << x << "}\n";
}