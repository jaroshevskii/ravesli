#include "Deck.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

/// Returns true if the player wants to hit.
bool playerWantsHit() {
  while (true) {
    std::cout << "Hit or stand?\n"
              << "> [h/s] ";
    auto character = char{};
    std::cin >> character;
    std::cout << '\n';

    switch (character) {
    case 'h':
      return true;
    case 's':
      return false;
    default:
      std::cerr << "Oops! Looks like you entered the wrong character.\n\n";
      break;
    }
  }
}

/// Returns true if the player loses.
bool playerTurn(Deck &deck, Player &player) {
  while (true) {
    if (player.isBust()) {
      // A player can lose immediately if he has two aces at the start.
      std::cout << "You busted!\n";
      return true;
    } else {
      if (playerWantsHit()) {
        const auto playerCard = player.takeCard(deck);
        std::cout << "You have received a " << playerCard << " and now have "
                  << player.getScore() << '\n';
      } else {
        // The player did not lose.
        return false;
      }
    }
  }
}

// Returns true if the dealer losses.
bool dealerTurn(Deck &deck, Player &dealer) {
  while (dealer.getScore() < minDealerScore) {
    const auto dealerCard = dealer.takeCard(deck);
    std::cout << "The dealer received a " << dealerCard << " and now has "
              << dealer.getScore() << '\n';
  }

  if (dealer.isBust()) {
    std::cout << "The dealer busted!\n";
    return true;
  }
  return false;
}

/// Returns true if the player win.
bool playBlackjack(Deck &deck) {
  auto dealer = Player{};
  dealer.takeCard(deck);

  std::cout << "The dealer have: " << dealer.getScore() << '\n';

  auto player = Player{};
  player.takeCard(deck);
  player.takeCard(deck);

  std::cout << "You have: " << player.getScore() << "\n\n";

  if (playerTurn(deck, player)) {
    std::cout << '\n';
    return false;
  }
  if (dealerTurn(deck, dealer)) {
    std::cout << '\n';
    return true;
  }
  std::cout << '\n';
  return (player.getScore() > dealer.getScore());
}

int main() {
  auto deck = Deck{};
  deck.shuffle();

  if (playBlackjack(deck)) {
    std::cout << "You win!\n";
  } else {
    std::cout << "You lose!\n";
  }
  return 0;
}