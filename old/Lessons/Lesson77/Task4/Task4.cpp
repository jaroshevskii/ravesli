#include <iostream>

template <size_t Size> void sortArray(int (&array)[Size]) {
  bool isSwapped;

  for (int iteration = 0; iteration != Size - 1; ++iteration) {
    bool isSwapped = false;

    for (size_t index = 0; index != Size - 1 - iteration; ++index) {
      if (array[index] > array[index + 1]) {
        std::swap(array[index], array[index + 1]);
        isSwapped = true;
      }
    }

    if (!isSwapped) {
      std::cout << "Early termination on iteration: " << iteration << "\n";
      return;
    }
  }
}

int main() {
  const int size = 9;
  int array[size]{7, 5, 6, 4, 9, 8, 2, 1, 3};

  for (const auto &element : array)
    std::cout << element << ' ';

  std::cout << "- Before sorting\n";

  sortArray(array);

  for (const auto &element : array)
    std::cout << element << ' ';

  std::cout << "- After sorting\n";
  return 0;
}