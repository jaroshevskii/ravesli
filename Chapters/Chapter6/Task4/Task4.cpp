#include <iostream>

void print(const char *text) {
  while (*text != '\0') {
    std::cout << *text;
    ++text;
  }
  std::cout << "\n\n";
}

int main() {
  print("Hello, world!");
  return 0;
}