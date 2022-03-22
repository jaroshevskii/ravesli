#include <iostream>

int binarySearch(const int *array, int target, int min, int max) {
  int index;

  while (min <= max) {
    index = (min + max) / 2;

    if (target == array[index])
      return index;

    if (target < array[index])
      max = index - 1;
    else if (target > array[index])
      min = index + 1;
  }
  return 0; // I think returning a negative index is not a good idea.
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