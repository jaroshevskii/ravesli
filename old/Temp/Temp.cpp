#include <cassert>
#include <iostream>
#include <limits>

int getNumber() {
  int number;

  while (true) {
    std::cout << "> ";
    std::cin >> number;

    std::cin.clear();

    if (std::cin.eof())
      std::cerr << "error: std::cin.eof()\n";
    if (std::cin.fail())
      std::cerr << "error: std::cin.fail()\n";
    if (std::cin.good())
      std::cerr << "error: std::cin.good()\n";
    if (std::cin.bad())
      std::cerr << "error: std::cin.bad()\n";

    if (std::cin.good()) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return number;
    }

    std::cin.clear();

    if (std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'))
      std::cerr << "error: std::cin.ignore()\n";

    std::cerr << "error: some error.\n";
  }
}

void test(const int &number) {
  assert(number < 5);

  std::cout << "Test\n";
}

static_assert(sizeof(long) == 8, "long must be 8 bytes");
static_assert(sizeof(int) == 4, "int must be 4 bytes");

int main(int argc, char **argv) {

  std::cout << "Hello, world!\n";
  std::cin.get();
  system("sensors");

  /*
  for (int i = 0; i < argc; ++i) {
    std::cout << argv[i] << '\n';
  }
  */
  // test(4);

  /*
  std::cout << "Enter the number.\n";
  auto number1 = getNumber();
  std::cout << '\n';

  std::cout << "Enter the number.\n";
  auto number2 = getNumber();
  std::cout << '\n';

  std::cout << "Number1: " << number1 << "\n"
            << "Number2: " << number2 << '\n';
            */
  return 0;
}