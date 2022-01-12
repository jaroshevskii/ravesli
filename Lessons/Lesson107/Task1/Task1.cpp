#include <iostream>

int factorial(const int &n) {
  if (n <= 0)
    return n;
  if (n == 1)
    return n;
  return factorial(n - 1) * n;
}

int main() {
  const int numCount = 8;

  for (int count = 0; count < numCount; ++count)
    std::cout << "Factorial: " << factorial(count) << '\n';
  return 0;
}