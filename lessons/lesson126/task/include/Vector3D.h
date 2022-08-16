#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "Point3D.h"

/// Vector 3D.
class Vector3D {
private:
  double x{};
  double y{};
  double z{};

public:
  Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);

  auto print() const -> void;

  friend auto Point3D::moveByVector(const Vector3D &vector) -> void;
};

#endif // VECTOR3D_H