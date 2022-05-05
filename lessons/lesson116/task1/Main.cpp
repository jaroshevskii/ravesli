#include <iostream>

class Ball {
private:
  std::string myColor{};
  double myRadius{};

public:
  Ball(double radius) : myColor{"red"}, myRadius{radius} {}

  Ball(const std::string &color = "red", double radius = 20.0)
      : myColor{color}, myRadius{radius} {}

  void print() const {
    std::cout << "color: " << myColor << ", radius: " << myRadius << '\n';
  }
};

int main() {
  const auto def = Ball{};
  def.print();

  const auto black = Ball{"black"};
  black.print();

  const auto thirty = Ball{30.0};
  thirty.print();

  const auto blackThirty = Ball{"black", 30.0};
  blackThirty.print();
  return 0;
}