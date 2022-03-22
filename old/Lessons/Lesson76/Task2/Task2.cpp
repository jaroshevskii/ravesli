#include <iostream>

int getNumber(const int &min, const int &max) {
  std::cout << "Enter a number from " << min << " to " << max << ".\n";
  int number;
  
  while (true) {
    std::cout << "> ";
    std::cin >> number;

    if (number >= min && number <= max)
      return number;
    
    std::cout << "error: Invalid number.\n";
  }
}

template <size_t Size>
void printArray(const int (&array)[Size]) {
  std::cout << "Array:";

  for (const auto &element : array)
    std::cout << ' ' << element;
  std::cout << '\n';
}

template <size_t Size>
size_t getIndex(const int (&array)[Size], const int &number) {
  for (size_t i = 0; i != Size; ++i) {
    if (array[i] == number)
      return i;
  }

  std::cout << "error: The array does not have the " << number << ".\n";
  return 0;
}

int main() {
  const int number = getNumber(1, 9);

  const int array[]{7, 5, 6, 4, 9, 8, 2, 1, 3};
  printArray(array);

  const size_t index = getIndex(array, number);
  std::cout << "Index: " << index << "\n";
  return 0;
}