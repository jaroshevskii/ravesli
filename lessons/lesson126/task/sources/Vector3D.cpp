#include "Vector3D.h"

#include <iostream>

Vector3D::Vector3D(double x, double y, double z) : myX{x}, myY{y}, myZ{z} {}

void Vector3D::print() const {
  std::cout << "Vector{" << myX << ", " << myY << ", " << myZ << "}\n";
}