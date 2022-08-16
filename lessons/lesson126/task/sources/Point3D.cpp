#include "Point3D.h"
#include "Vector3D.h"

#include <iostream>

Point3D::Point3D(double x, double y, double z) : x{x}, y{y}, z{z} {}

auto Point3D::print() const -> void {
  std::cout << "Point{" << x << ", " << y << ", " << z << "}\n";
}

auto Point3D::moveByVector(const Vector3D &vector) -> void {
  x += vector.x;
  y += vector.y;
  z += vector.z;
}