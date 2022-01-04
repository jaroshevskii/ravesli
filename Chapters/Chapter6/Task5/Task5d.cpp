#include <iostream>

int main() {
  double d = 4.7;
  auto ptr = &d;

  std::cout << *ptr << '\n'
            << '\n';
  return 0;
}