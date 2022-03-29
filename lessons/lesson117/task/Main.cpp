#include <iostream>

class RGBA {
private:
  uint8_t myRed{};
  uint8_t myGreen{};
  uint8_t myBlue{};
  uint8_t myAlpha{};

public:
  RGBA() = default;

  RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255)
      : myRed{red}, myGreen{green}, myBlue{blue}, myAlpha{alpha} {}

  void print() const {
    std::cout << "r = " << static_cast<int>(myRed)
              << " g = " << static_cast<int>(myGreen)
              << " b = " << static_cast<int>(myBlue)
              << " a = " << static_cast<int>(myAlpha) << '\n';
  }
};

int main() {
  const RGBA color{0, 135, 135};
  color.print();
  return 0;
}