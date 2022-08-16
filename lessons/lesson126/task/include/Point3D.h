#ifndef POINT3D_H
#define POINT3D_H

class Vector3D;

/// Point 3D.
class Point3D {
private:
  double x{};
  double y{};
  double z{};

public:
  Point3D(double x = 0.0, double y = 0.0, double z = 0.0);

  auto print() const -> void;

  auto moveByVector(const Vector3D &vector) -> void;
};

#endif // POINT3D_H