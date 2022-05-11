#ifndef CARD_H
#define CARD_H

/// Card.
class Card {
public:
  /// Card rank.
  enum class Rank {
    Number2,
    Number3,
    Number4,
    Number5,
    Number6,
    Number7,
    Number8,
    Number9,
    Number10,
    Jack,
    Queen,
    King,
    Ace,
    MaxRanks
  };

  /// Card suit.
  enum class Suit { Club, Diamond, Heart, Spade, MaxSuits };

private:
  Rank myRank{};
  Suit mySuit{};

public:
  /// Default constructor.
  Card() = default;

  /// Constructor.
  Card(const Rank &rank, const Suit &suit);

  /// Pints card rank and suit.
  void print() const;

  /// Returns the value of the rank.
  int getValueOfRank() const;
};

#endif // CARD_H