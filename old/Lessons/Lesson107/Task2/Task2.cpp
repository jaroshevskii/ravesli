#include <iostream>

/// Returns the sum of the digits of a number.
int getSumOfDigits(int number) {
  if (number < 10) {
    return number;
  }
  return getSumOfDigits(number / 10) + number % 10;
}

int main() {
  const int number = 83569;
  std::cout << "Sum of digits: " << getSumOfDigits(number) << '\n';
  return 0;
}
