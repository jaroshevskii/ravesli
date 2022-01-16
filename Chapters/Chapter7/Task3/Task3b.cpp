#include <iostream>

int binarySearch(const int *array, int target, int min, int max) {
  if (min > max)
    return 0; // I still think that returning a negative index is not a good
              // idea.

  int index = (min + max) / 2;

  if (target < array[index])
    return binarySearch(array, target, min, index - 1);
  if (target > array[index])
    return binarySearch(array, target, index + 1, max);

  return index;
}

int main() {
  const int array[]{4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50};

  std::cout << "Enter a number\n"
            << "> ";
  int x;
  std::cin >> x;
  std::cout << '\n';

  const int index = binarySearch(array, x, 0, 14);

  if (array[index] == x) {
    std::cout << "Good! Your value " << x << " is on position " << index
              << " in array!\n";
  } else {
    std::cout << "Fail! Your value " << x << " isn't in array!\n";
  }
  return 0;
}