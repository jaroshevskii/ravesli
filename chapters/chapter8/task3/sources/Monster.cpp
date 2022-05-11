#include "Monster.h"
#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

Monster::Monster(const Type &type, const std::string &name, int health)
    : myType{type}, myName{name}, myHealth{health} {}

/// Returns the monster type as a string.
std::string_view Monster::getTypeString() const {
  switch (myType) {
  case Monster::Type::Dragon:
    return "Dragon";
  case Monster::Type::Goblin:
    return "Goblin";
  case Monster::Type::Ogre:
    return "Ogre";
  case Monster::Type::Orc:
    return "Orc";
  case Monster::Type::Skeleton:
    return "Skeleton";
  case Monster::Type::Troll:
    return "Troll";
  case Monster::Type::Vampire:
    return "Vampire";
  case Monster::Type::Zombie:
    return "Zombie";
  default:
    return "Unknown";
  }
}

/// Prints information about the monster.
void Monster::print() const {
  std::cout << myName << " is the " << getTypeString() << " that has "
            << myHealth << " health points.\n";
}

/// Generate a random number between min and max (inclusive).
/// Assumes srand() has already been called.
/// Assumes max - min <= RAND_MAX.
int MonsterGenerator::getRandomNumber(int min, int max) {
  // Static used for efficiency, so we only calculate this value once.
  static constexpr auto fraction = 1.0 / (RAND_MAX + 1.0);

  // Evenly distribute the random number across our range.
  return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

/// Returns the generated monster.
Monster MonsterGenerator::generateMonster() {
  // Generate monster type.
  const auto type = static_cast<Monster::Type>(
      getRandomNumber(0, static_cast<int>(Monster::Type::MaxMonsterTypes) - 1));
  
  static constexpr auto names = std::array{
      "Shadelich",
      "Voodoomutant",
      "Grimevine",
      "Grimefigure",
      "The Colossal Entity",
      "The Haunting Revenant",
      "The Cruel Vermin",
      "The Onyx Vision Deer",
      "The Blood-Eyed Vision Alligator",
      "The Brutal Preying Frog",
  };
  
  // Generate monster name.
  const auto name = names[getRandomNumber(0, names.size() - 1)];
  // Generate monster health.
  const auto health = getRandomNumber(1, 100);

  return Monster{type, name, health};
}