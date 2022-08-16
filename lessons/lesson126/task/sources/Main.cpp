#include "Point3D.h"
#include "Vector3D.h"

auto main() -> int {
  auto point = Point3D{3.0, 4.0, 5.0};
  const auto vector = Vector3D{3.0, 3.0, -2.0};

  point.print();
  point.moveByVector(vector);
  point.print();
  return 0;
}