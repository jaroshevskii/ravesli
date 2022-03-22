#include <iostream>

int getNumber() {
  std::cout << "> ";
  int number;
  std::cin >> number;
  return number;
}

void printBinaryDigits(const unsigned int &number) {
  if (number == 0)
    return;

  printBinaryDigits(number / 2);

  std::cout << number % 2;
}

void printBinary(const int &number){
  if (number == 0)
    std::cout << number;

  printBinaryDigits(static_cast<unsigned int>(number));
}

int main() {
  std::cout << "Enter the number.\n";
  int number = getNumber();
  std::cout << '\n';

  std::cout << number << " (decimal) = ";
  printBinary(number);
  std::cout << " (binary)\n";
  return 0;
}