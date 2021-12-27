#include "Constants.h"

#include <iostream>

/// Отримати висоту вежі.
int getHeightOfTower() {
  std::cout << "Enter the height of the tower (metres).\n"
            << "> ";
  int heightOfTower;
  std::cin >> heightOfTower;
  return heightOfTower;
}

/// Отримати висоту м'яча.
double getHeightOfBall(const int &heightOfTower, const int &seconds) {
  return heightOfTower - constants::gravity * seconds * seconds / 2;
}

/// Надрукувати висоту м'яча.
void printHeightOfBall(const double &heightOfBall, const int &seconds) {
  if (heightOfBall > 0.0) {
    std::cout << "At " << seconds
              << " seconds, the ball is at height: " << heightOfBall
              << " meters\n";
  } else {
    std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
  }
}

int main() {
  const int heightOfTower = getHeightOfTower();

  double heightOfBall = heightOfTower;

  for (int seconds = 0; heightOfBall > 0.0; ++seconds) {
    heightOfBall = getHeightOfBall(heightOfTower, seconds);
    printHeightOfBall(heightOfBall, seconds);
  }
  return 0;
}