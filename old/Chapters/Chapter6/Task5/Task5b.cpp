#include <iostream>

int main() {
  int a = 4;
  int b = 6;

  int *ptr = &a;
  std::cout << *ptr << '\n';
  
  *ptr = 7;
  std::cout << *ptr << '\n';

  ptr = &b;
  std::cout << *ptr << '\n'
            << '\n';
  return 0;
}