#include "Console.h"
#include <iostream>

void
Console::play()
{
  showGreetings();
  blackJack.startGame();

  while (blackJack.getState() != BlackJack::State::GAME_END) {
    if (askPlayerPlay()) {
      blackJack.startGameRound();
      while (blackJack.getState() != BlackJack::State::GAME_ROUND_END) {
        showPlayerCardMessage();
        if (askPlayerPlayToHitOrStand()) {
          blackJack.playerHitCard();
        } else {
          blackJack.playerStand();
        }
      }
      showPlayerCardMessage();
      showGameRoundResultMessage();
    } else {
      blackJack.endGame();
    }
  }

  showExitMessage();
}

bool
Console::askPlayerPlayToHitOrStand()
{
  std::cout << "Press 'h' for Hit and 's' for Stand" << std::endl;
  std::string keyInput;
  std::cin >> keyInput;
  if (keyInput == "h" || keyInput == "H") {
    return true;
  } else if (keyInput == "s" || keyInput == "S") {
    return false;
  } else {
    return askPlayerPlayToHitOrStand();
  }
}

bool
Console::askPlayerPlay()
{
  std::cout << "Want to continue play? Press 'y' for yes and 'n' for no."
            << std::endl;
  std::string keyInput;
  std::cin >> keyInput;
  if (keyInput == "n" || keyInput == "N") {
    return false;
  } else if (keyInput == "y" || keyInput == "Y") {
    return true;
  } else {
    return askPlayerPlay();
  }
}

void
Console::showGreetings()
{
  std::cout << "Black Jack Game" << std::endl;
  std::cout << "Welcome " << blackJack.getPlayer().getName() << std::endl;
  std::cout << "I am " << blackJack.getDealer().getName()
            << ", Your Dealer. Lets play!" << std::endl;
}

void
Console::showExitMessage()
{
  std::cout << "Thanks for playing. Bye " << blackJack.getPlayer().getName()
            << std::endl;
}

void
Console::showPlayerCardMessage()
{
  std::vector<Cards::Card> cards = blackJack.getPlayer().getCards();
  std::string message;
  for (auto const& card : cards) {
    message += Cards::getCardName(card) + "=" +
               std::to_string((int)Cards::getCardValue(card)) + ",";
  }

  std::cout << "Your card in hand: " << message << std::endl;
}

void
Console::showGameRoundResultMessage()
{
  std::cout << "-----Game Result-----" << std::endl;
  std::string winner;
  switch (blackJack.getWinner()) {
    case BlackJack::PLAYER_BUSTED:
      winner = "Player busted. Dealer Wins";
      break;
    case BlackJack::DEALER_BUSTED:
      winner = "Dealer busted. Player Wins";
      break;
    case BlackJack::PLAYER_WON:
      winner = "Player won. Player:" +
               std::to_string((int)blackJack.getPlayer().getCardsPoints()) +
               " Dealer:" +
               std::to_string((int)blackJack.getDealer().getCardsPoints());
      break;
    case BlackJack::DEALER_WON:
      winner = "Dealer won. Dealer:" +
               std::to_string((int)blackJack.getDealer().getCardsPoints()) +
               " Player:" +
               std::to_string((int)blackJack.getPlayer().getCardsPoints());
      break;
    case BlackJack::DRAW:
      winner = "Draw. Dealer:" +
               std::to_string((int)blackJack.getDealer().getCardsPoints()) +
               " Player:" +
               std::to_string((int)blackJack.getPlayer().getCardsPoints());
      break;

    default:
      break;
  }

  std::cout << winner << std::endl;
}