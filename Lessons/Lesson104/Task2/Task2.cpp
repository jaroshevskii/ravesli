#include <iostream>

typedef double (*arithmeticFunction)(const double &, const double &);

struct Arithmetic {
  char oper;
  arithmeticFunction function;
};

double add(const double &a, const double &b) { return a + b; }

double subtract(const double &a, const double &b) { return a - b; }

double multiply(const double &a, const double &b) { return a * b; }

double divide(const double &a, const double &b) { return a / b; }

static Arithmetic arithmeticArray[]{
    {'+', add}, {'-', subtract}, {'*', multiply}, {'/', divide}};

double getNumber() {
  std::cout << "Enter the number.\n"
            << "> ";
  double number;
  std::cin >> number;
  return number;
}

char getOperator() {
  std::cout << "Enter the operator.\n";
  char oper;

  while (true) {
    std::cout << "> ";
    std::cin >> oper;

    switch (oper) {
    case '+':
    case '-':
    case '*':
    case '/':
      return oper;
    default:
      std::cerr << "ERROR: Invalid operator."
                << "The operator can be +, -, * and /.\n";
      break;
    }
  }
}

arithmeticFunction getArithmeticFunction(const char &oper) {
  for (const auto &arithmetic : arithmeticArray) {
    if (arithmetic.oper == oper)
      return arithmetic.function;
  }
  return add; // add() default function
}

int main() {
  const double a = getNumber();
  const char oper = getOperator();
  const double b = getNumber();
  std::cout << '\n';

  const auto function = getArithmeticFunction(oper);

  std::cout << a << ' ' << oper << ' ' << b << " = " << function(a, b)
            << "\n\n";
  return 0;
}
