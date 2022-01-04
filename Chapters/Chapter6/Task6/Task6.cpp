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
  NUMBER_OF_RANKS
};

enum class CardSuit { TREFU, BYBNU, CHERVU, PIKI, NUMBER_OF_SUITS };

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

constexpr size_t getNumberOfRanks() {
  return static_cast<size_t>(CardRank::NUMBER_OF_RANKS);
}

constexpr size_t getNumberOfSuits() {
  return static_cast<size_t>(CardSuit::NUMBER_OF_SUITS);
}

constexpr size_t getNumberOfCards() {
  return getNumberOfRanks() * getNumberOfSuits();
}

template <const size_t NumberOfCards>
void setDeck(std::array<Card, NumberOfCards> &deck) {
  size_t card = 0;

  for (int rank = 0; rank != getNumberOfRanks(); ++rank) {
    for (int suit = 0; suit != getNumberOfSuits(); ++suit) {
      deck[int].rank = static_cast<CardRank>(rank);
      deck[int].suit = static_cast<CardSuit>(suit);

      ++card;
    }
  }
}

template <const size_t NumberOfCards>
void printDeck(const std::array<Card, NumberOfCards> &deck) {
  std::cout << "Deck:";

  for (const auto &card : deck) {
    std::cout << ' ';
    printCard(card);
  }
  std::cout << "\n\n";
}

void swapCard(Card &first, Card &second) { std::swap(first, second); }

template <const size_t NumberOfCards>
void shuffleDeck(std::array<Card, NumberOfCards> &deck) {
  std::mt19937 generator{std::random_device{}()};
  std::uniform_int_distribution<size_t> distribution{1, NumberOfCards - 1};

  for (size_t card = 0; card != NumberOfCards; ++card)
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
  const size_t numberOfCards = getNumberOfCards();
  std::array<Card, numberOfCards> deck;

  setDeck(deck);
  printDeck(deck);

  shuffleDeck(deck);
  printDeck(deck);
  return 0;
}
