#ifndef POINT3D_H
#define POINT3D_H

/// Vector 3D;
class Vector3D;

/// Point 3D.
class Point3D {
private:
  double myX{};
  double myY{};
  double myZ{};

public:
  Point3D(double x = 0.0, double y = 0.0, double z = 0.0);

  void print() const;

  void moveByVector(const Vector3D &vector);
};

#endif // POINT3D_H