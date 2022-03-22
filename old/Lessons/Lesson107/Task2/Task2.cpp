#include <iostream>

int getSumOfdigits(const int &number) {
  if (number < 10)
    return number;
  return getSumOfdigits(number / 10) + number % 10;
}

int main() {
  const int number = 83569;
  std::cout << "Sum of digits: " << getSumOfdigits(number) << '\n';
  return 0;
}