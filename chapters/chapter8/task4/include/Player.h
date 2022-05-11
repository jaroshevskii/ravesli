#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"

/// Max score before losing.
constexpr auto maxScore = 21;
/// Min score that the dealer must have.
constexpr auto minDealerScore = 17;

/// Player.
class Player {
private:
  int myScore{};

public:
  /// Default constructor.
  Player() = default;

  /// Take a card from the deck.
  int takeCard(Deck &deck);

  /// Returns the player score.
  int getScore() const;
  
  /// Returns true if the player bust.
  bool isBust() const;
};

#endif // PLAYER_H