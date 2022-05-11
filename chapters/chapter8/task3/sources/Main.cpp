#include "Monster.h"
#include <cstdlib>
#include <ctime>

int main() {
  // Set initial seed value to system clock.
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  
  const auto monster = MonsterGenerator::generateMonster();
  monster.print();
  return 0;
}