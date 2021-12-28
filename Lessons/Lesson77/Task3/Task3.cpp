#include <iostream>

int main() {
  const int size = 9;
  int array[size]{7, 5, 6, 4, 9, 8, 2, 1, 3};

  for (const auto &element : array)
    std::cout << element << ' ';

  std::cout << "- Before sorting\n";

  // Start sorting the array
  for (int i = 0; i != size - 1; ++i) {
    for (size_t index = 0; index != size - 1; ++index) {
      if (array[index] > array[index + 1])
        std::swap(array[index], array[index + 1]);
    }
  }
  // End sorting the array

  for (const auto &element : array)
    std::cout << element << ' ';

  std::cout << "- After sorting\n";
  return 0;
}