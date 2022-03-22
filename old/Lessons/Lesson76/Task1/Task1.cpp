#include <iostream>

int main() {
  const int array[]{7, 5, 6, 4, 9, 8, 2, 1, 3};

  std::cout << "Array:";

  for (const auto &element : array)
    std::cout << ' ' << element;
  std::cout << '\n';
  return 0;
}