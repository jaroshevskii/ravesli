#include <iostream>
#include <string>

class Thing {
private:
  std::string myColor{"blue"};
  double myRadius{20.0};

public:
  /// Default constructor with no parameters.
  Thing() = default;

  /// Constructor with color parameter (default value provided for radius).
  Thing(const std::string &color) : myColor{color} {}

  /// Constructor with radius parameter (default value provided for color).
  Thing(double radius) : myRadius{radius} {}

  /// Constructor with color and radius parameters.
  Thing(const std::string &color, double radius)
      : myColor{color}, myRadius{radius} {}

  void print() const {
    std::cout << "color: " << myColor << " and radius: " << myRadius << '\n';
  }
};

int main() {
  const Thing defl{};
  defl.print();

  const Thing red{"red"};
  red.print();

  const Thing thirty{30.0};
  thirty.print();

  const Thing redThirty{"red", 30.0};
  redThirty.print();
  return 0;
}