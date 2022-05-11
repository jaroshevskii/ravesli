#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <array>
#include <string_view>

/// Deck.
class Deck {
public:
  using DeckType = std::array<Card, 52>;
  using IndexType = DeckType::size_type;

private:
  DeckType myDeck{};
  IndexType myCardIndex{0};

public:
  /// Constructor.
  Deck();

  /// Prints a deck.
  void print(std::string_view terminator = "\n") const;

  /// Shuffle the deck.
  void shuffle();

  /// Returns the deal card.
  const Card &getDealCard();
};

#endif // DECK_H