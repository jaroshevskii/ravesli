#include <iostream>

template <typename Type> void swap(Type &first, Type &second) {
  const auto temp{first};
  first = second;
  second = temp;
}

int main() {
  std::cout << "> A = ";
  int a;
  std::cin >> a;

  std::cout << "> B = ";
  int b;
  std::cin >> b;
  std::cout << '\n';

  if (a == b)
    std::cout << "A and B are equal.\n"
              << '\n';
  else
    swap(a, b);

  std::cout << "A:" << a << "\n"
            << "B:" << b << "\n"
            << '\n';
  return 0;
}