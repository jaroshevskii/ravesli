#include "Point3D.h"
#include "Vector3D.h"

#include <iostream>

Point3D::Point3D(double x, double y, double z) : myX{x}, myY{y}, myZ{z} {}

void Point3D::print() const {
  std::cout << "Point{" << myX << ", " << myY << ", " << myZ << "}\n";
}

void Point3D::moveByVector(const Vector3D &vector) {
  myX += vector.myX;
  myY += vector.myY;
  myZ += vector.myZ;
}