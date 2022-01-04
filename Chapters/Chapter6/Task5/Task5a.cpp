#include <iostream>

int main() {
  int array[6]{0, 2, 4, 7, 9};

  for (int count = 0; count < 6; ++count)
    std::cout << array[count] << ' ';
  std::cout << '\n';
  return 0;
}