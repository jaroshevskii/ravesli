#ifndef POINT_H
#define POINT_H

/// Point.
class Point {
private:
  double myA{};
  double myB{};

public:
  Point(double a = 0.0, double b = 0.0);
  
  /// Prints a point.
  void print() const;

  /// Returns the distance between two points.
  friend double distanceFrom(const Point &first, const Point &second);
};

#endif // POINT_H