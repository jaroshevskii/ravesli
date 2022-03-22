#include <iostream>

int getPositiveNumber() {
  int number;

  while (true) {
    std::cout << "> ";
    std::cin >> number;

    if (number >= 0)
      return number;

    std::cerr << "ERROR: The number must be positive.\n";
  }
}

void printBinary(const int &number) {
  if (number == 0)
    return;

  printBinary(number / 2);

  std::cout << number % 2;
}

int main() {
  std::cout << "Enter a positive number.\n";
  int number = getPositiveNumber();
  std::cout << '\n';

  std::cout << number << " (decimal) = ";
  printBinary(number);
  std::cout << " (binary)\n";
  return 0;
}