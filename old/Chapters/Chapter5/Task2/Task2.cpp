#include <iostream>
#include <random>

void game(const int &generatedNumber, const int &numberOfAttempts) {
  std::cout << "A random number is generated. You have " << numberOfAttempts
            << " attempts to guess this number.\n";

  int playerNumber;

  for (int attempt = 1; attempt <= numberOfAttempts; ++attempt) {
    std::cout << "Attemp #" << attempt << "\n"
              << "> ";
    std::cin >> playerNumber;

    if (playerNumber == generatedNumber) {
      std::cout << "You win!\n";
      return;
    }

    if (playerNumber > generatedNumber)
      std::cout << "Your number is greater.\n";
    if (playerNumber < generatedNumber)
      std::cout << "Your number is less.\n";
  }

  std::cout << "You lost!\n"
            << "Generated number is: " << generatedNumber << '\n';
}

int main() {
  std::mt19937 generator{std::random_device{}()};
  std::uniform_int_distribution<int> distribution{1, 100};

  const int numberOfAttempts = 7;

  while (true) {
    game(distribution(generator), numberOfAttempts);

    std::cout << "Do you want to play again (y/n)?\n"
              << "> ";
    char x;
    std::cin >> x;

    if (x == 'n')
      return 0;
  }
  return 0;
}
