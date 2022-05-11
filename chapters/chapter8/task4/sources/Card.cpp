#include "Card.h"
#include <iostream>

/// Constructor.
Card::Card(const Rank &rank, const Suit &suit) : myRank{rank}, mySuit{suit} {}

/// Pints card rank and suit.
void Card::print() const {
  // Prints card rank.
  switch (myRank) {
  case Rank::Number2:
    std::cout << '2';
    break;
  case Rank::Number3:
    std::cout << '3';
    break;
  case Rank::Number4:
    std::cout << '4';
    break;
  case Rank::Number5:
    std::cout << '5';
    break;
  case Rank::Number6:
    std::cout << '6';
    break;
  case Rank::Number7:
    std::cout << '7';
    break;
  case Rank::Number8:
    std::cout << '8';
    break;
  case Rank::Number9:
    std::cout << '9';
    break;
  case Rank::Number10:
    std::cout << 'T';
    break;
  case Rank::Jack:
    std::cout << 'J';
    break;
  case Rank::Queen:
    std::cout << 'Q';
    break;
  case Rank::King:
    std::cout << 'K';
    break;
  case Rank::Ace:
    std::cout << 'A';
    break;
  default:
    std::cout << '?';
    break;
  }

  // Prints card suit.
  switch (mySuit) {
  case Suit::Club:
    std::cout << 'C';
    break;
  case Suit::Diamond:
    std::cout << 'D';
    break;
  case Suit::Heart:
    std::cout << 'H';
    break;
  case Suit::Spade:
    std::cout << 'S';
    break;
  default:
    std::cout << '?';
    break;
  }
}

/// Returns the value of the rank.
int Card::getValueOfRank() const {
  switch (myRank) {
  case Rank::Number2:
    return 2;
  case Rank::Number3:
    return 3;
  case Rank::Number4:
    return 4;
  case Rank::Number5:
    return 5;
  case Rank::Number6:
    return 6;
  case Rank::Number7:
    return 7;
  case Rank::Number8:
    return 8;
  case Rank::Number9:
    return 9;
  case Rank::Number10:
    return 10;
  case Rank::Jack:
    return 10;
  case Rank::Queen:
    return 10;
  case Rank::King:
    return 10;
  case Rank::Ace:
    return 11;
  default:
    return 0;
  }
}