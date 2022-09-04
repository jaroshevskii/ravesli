#include "Welcome.h"
#include <iostream>

Welcome::Welcome() {
  data = new char[14];
  const char *init = "Hello, World!";

  for (int i = 0; i < 14; ++i) {
    data[i] = init[i];
  }
}

Welcome::~Welcome() { delete[] data; }

void Welcome::print() const { std::cout << data << '\n'; }