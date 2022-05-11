#include "Player.h"

/// Take a card from the deck.
int Player::takeCard(Deck &deck) {
  auto value = deck.getDealCard().getValueOfRank();
  myScore += value;
  return value;
}

/// Returns the player score.
int Player::getScore() const { return myScore; }

/// Returns true if the player loses.
bool Player::isBust() const { return myScore > maxScore; }