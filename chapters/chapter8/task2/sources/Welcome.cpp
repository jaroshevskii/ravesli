#include "Welcome.h"
#include <iostream>

Welcome::Welcome() {
  myData = new char[14];
  const auto *init = "Hello, World!";

  for (auto i = 0; i < 14; ++i) {
    myData[i] = init[i];
  }
}

Welcome::~Welcome() { delete[] myData; }

/// Prints a welcome messange.
void Welcome::print() const { std::cout << myData << '\n'; }