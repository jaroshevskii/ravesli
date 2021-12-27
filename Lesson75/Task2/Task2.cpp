#include <array>
#include <iostream>

namespace animals {

enum Animals { CHICKEN, LION, GIRAFFE, ELEPHANT, DUCK, SNAKE, MAX_ANIMALS };

} // end namespace animals

int main() {
  std::array<int, animals::MAX_ANIMALS> legs{2, 4, 4, 4, 2, 0};

  std::cout << "An elephant has " << legs.at(animals::ELEPHANT) << " legs.\n";
  return 0;
}