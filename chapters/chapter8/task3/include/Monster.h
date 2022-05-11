#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <string_view>

/// Monster.
class Monster {
public:
  /// Type.
  enum class Type {
    Dragon,
    Goblin,
    Ogre,
    Orc,
    Skeleton,
    Troll,
    Vampire,
    Zombie,
    MaxMonsterTypes
  };

private:
  Type myType{};
  std::string myName{};
  int myHealth{};

public:
  Monster(const Type &type, const std::string &name, int health);

  /// Returns the monster type as a string.
  std::string_view getTypeString() const;

  /// Prints information about the monster.
  void print() const;
};

/// Monster generator.
class MonsterGenerator {
public:
  /// Generate a random number between min and max (inclusive).
  /// Assumes srand() has already been called.
  /// Assumes max - min <= RAND_MAX.
  static int getRandomNumber(int min, int max);

  /// Returns the generated monster.
  static Monster generateMonster();
};

#endif // MONSTER_H