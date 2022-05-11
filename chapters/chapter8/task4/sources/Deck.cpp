#include "Deck.h"
#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <random>
#include <string_view>

/// Constructor.
Deck::Deck() {
  auto index = IndexType{0};

  for (auto rank = 0; rank < static_cast<int>(Card::Rank::MaxRanks); ++rank) {
    for (auto suit = 0; suit < static_cast<int>(Card::Suit::MaxSuits); ++suit) {
      myDeck[index] =
          Card{static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)};
      ++index;
    }
  }
}

/// Prints deck.
void Deck::print(std::string_view terminator) const {
  std::cout << "Deck:";

  for (const auto &card : myDeck) {
    std::cout << ' ';
    card.print();
  }
  std::cout << '\n' << terminator;
}

/// Shuffle the deck.
void Deck::shuffle() {
  /// Create a twister engine.
  static auto twisterEngine =
      std::mt19937{static_cast<std::mt19937::result_type>(std::time(nullptr))};

  // Shuffle the deck.
  std::shuffle(myDeck.begin(), myDeck.end(), twisterEngine);
  
  // Reset the card index.
  myCardIndex = 0;
}

/// Returns the deal card.
const Card &Deck::getDealCard() {
  assert(myCardIndex < myDeck.size());
  return myDeck[myCardIndex++];
}