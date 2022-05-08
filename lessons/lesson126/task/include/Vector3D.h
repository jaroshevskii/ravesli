#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3D.h"

/// Vector 3D.
class Vector3D {
private:
  double myX{};
  double myY{};
  double myZ{};

public:
  Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);

  void print() const;

  friend void Point3D::moveByVector(const Vector3D &vector);
};

#endif // VECTOR3D_H