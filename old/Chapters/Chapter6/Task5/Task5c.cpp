#include <iostream>

void printArray(const int *array, const size_t &size) {
  std::cout << "Array:";
  for (size_t i = 0; i < size; ++i)
    std::cout << ' ' << array[i];
  std::cout << "\n\n";
}

int main() {
  int array[]{8, 6, 4, 2, 0};
  printArray(array, sizeof(array) / sizeof(int));
  return 0;
}