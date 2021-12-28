#include <iostream>

int main() {
  const int size = 5;
  int array[size]{30, 50, 20, 10, 40};

  for (size_t startIndex = 0; startIndex < size - 1; ++startIndex) {
    int smallestIndex = startIndex;

    for (size_t currentIndex = startIndex + 1; currentIndex < size;
         ++currentIndex) {
      if (array[currentIndex] > array[smallestIndex])
        smallestIndex = currentIndex;
    }

    std::swap(array[startIndex], array[smallestIndex]);
  }
  
  std::cout << "Array:";

  for (const auto &element : array)
    std::cout << ' ' << element;
  std::cout << '\n';
  return 0;
}