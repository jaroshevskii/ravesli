#include <algorithm>
#include <iostream>

void setNames(std::string *names, const size_t &numberOfNames) {
  std::cout << "Enter names.\n";

  for (size_t i = 0; i < numberOfNames; ++i) {
    std::cout << "> #" << i + 1 << " = ";
    std::cin >> names[i];
  }
  std::cout << '\n';
}

void printNames(std::string *names, const size_t &numberOfNames) {
  std::cout << "Names:\n";
  for (size_t i = 0; i < numberOfNames; ++i)
    std::cout << "  #" << i + 1 << ": " << names[i] << '\n';
  std::cout << '\n';
}

int main() {
  std::cout << "Enter the number of names.\n"
            << "> ";
  size_t numberOfNames;
  std::cin >> numberOfNames;
  std::cout << '\n';

  auto *names = new std::string[numberOfNames];
  setNames(names, numberOfNames);

  std::sort(names, names + numberOfNames);
  printNames(names, numberOfNames);

  delete[] names;
  return 0;
}