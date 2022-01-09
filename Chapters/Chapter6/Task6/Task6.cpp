#include <array>
#include <iostream>
#include <random>

enum class CardRank {
  NUMBER_2,
  NUMBER_3,
  NUMBER_4,
  NUMBER_5,
  NUMBER_6,
  NUMBER_7,
  NUMBER_8,
  NUMBER_9,
  NUMBER_10,
  VALET,
  DAMA,
  KOROL,
  TYZ,
  NUM_RANKS
};

enum class CardSuit { TREFU, BYBNU, CHERVU, PIKI, NUM_SUITS };

struct Card {
  CardRank rank;
  CardSuit suit;
};

void printCard(const Card &card) {
  switch (card.rank) {
  case CardRank::NUMBER_2:
    std::cout << "2";
    break;
  case CardRank::NUMBER_3:
    std::cout << "3";
    break;
  case CardRank::NUMBER_4:
    std::cout << "4";
    break;
  case CardRank::NUMBER_5:
    std::cout << "5";
    break;
  case CardRank::NUMBER_6:
    std::cout << "6";
    break;
  case CardRank::NUMBER_7:
    std::cout << "7";
    break;
  case CardRank::NUMBER_8:
    std::cout << "8";
    break;
  case CardRank::NUMBER_9:
    std::cout << "9";
    break;
  case CardRank::NUMBER_10:
    std::cout << "10";
    break;
  case CardRank::VALET:
    std::cout << "V";
    break;
  case CardRank::DAMA:
    std::cout << "D";
    break;
  case CardRank::KOROL:
    std::cout << "K";
    break;
  case CardRank::TYZ:
    std::cout << "T";
    break;
  default:
    std::cout << "?";
  }

  switch (card.suit) {
  case CardSuit::TREFU:
    std::cout << "T";
    break;
  case CardSuit::BYBNU:
    std::cout << "B";
    break;
  case CardSuit::CHERVU:
    std::cout << "C";
    break;
  case CardSuit::PIKI:
    std::cout << "P";
    break;
  default:
    std::cout << "?";
  }
}

constexpr size_t getNumRanks() {
  return static_cast<size_t>(CardRank::NUM_RANKS);
}

constexpr size_t getNumSuits() {
  return static_cast<size_t>(CardSuit::NUM_SUITS);
}

constexpr size_t getNumCards() { return getNumRanks() * getNumSuits(); }

template <size_t NumCards>
void setDeck(std::array<Card, NumCards> &deck) {
  size_t card = 0;

  for (int rank = 0; rank < getNumRanks(); ++rank) {
    for (int suit = 0; suit < getNumSuits(); ++suit) {
      deck[card].rank = static_cast<CardRank>(rank);
      deck[card].suit = static_cast<CardSuit>(suit);

      ++card;
    }
  }
}

template <size_t NumCards>
void printDeck(const std::array<Card, NumCards> &deck) {
  std::cout << "Deck:";

  for (const auto &card : deck) {
    std::cout << ' ';
    printCard(card);
  }
  std::cout << "\n\n";
}

void swapCard(Card &first, Card &second) { std::swap(first, second); }

template <size_t NumCards>
void shuffleDeck(std::array<Card, NumCards> &deck) {
  std::mt19937 generator{std::random_device{}()};
  std::uniform_int_distribution<size_t> distribution{0, NumCards - 1};

  for (size_t card = 0; card < NumCards; ++card)
    swapCard(deck[card], deck[distribution(generator)]);
}

int getCardValue(const Card &card) {
  switch (card.rank) {
  case CardRank::NUMBER_2:
    return 2;
  case CardRank::NUMBER_3:
    return 3;
  case CardRank::NUMBER_4:
    return 4;
  case CardRank::NUMBER_5:
    return 5;
  case CardRank::NUMBER_6:
    return 6;
  case CardRank::NUMBER_7:
    return 7;
  case CardRank::NUMBER_8:
    return 8;
  case CardRank::NUMBER_9:
    return 9;
  case CardRank::NUMBER_10:
  case CardRank::VALET:
  case CardRank::DAMA:
  case CardRank::KOROL:
    return 10;
  case CardRank::TYZ:
    return 11;
  default:
    return 0;
  }
}

int main() {
  const size_t numCards = getNumCards();
  std::array<Card, numCards> deck;

  setDeck(deck);
  printDeck(deck);

  shuffleDeck(deck);
  printDeck(deck);
  return 0;
}
