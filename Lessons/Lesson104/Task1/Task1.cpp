#include <iostream>

typedef double (*arithmeticFunction)(const double &, const double &);

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

double add(const double &a, const double &b) { return a + b; }

double subtract(const double &a, const double &b) { return a - b; }

double multiply(const double &a, const double &b) { return a * b; }

double divide(const double &a, const double &b) { return a / b; }

arithmeticFunction getArithmeticFunction(const char &oper) {
  switch (oper) {
  default: // add() default function
  case '+':
    return add;
  case '-':
    return subtract;
  case '*':
    return multiply;
  case '/':
    return divide;
  }
}

int main() {
  double a = getNumber();
  char oper = getOperator();
  double b = getNumber();
  std::cout << '\n';

  arithmeticFunction arithmetic = getArithmeticFunction(oper);

  std::cout << a << ' ' << oper << ' ' << b << " = " << arithmetic(a, b)
            << "\n\n";
  return 0;
}