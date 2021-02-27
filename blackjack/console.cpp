#include "console.hpp"
#include <iostream>
#include <map>

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
  std::string playerPoints =
    std::to_string((int)blackJack.getPlayer().getCardsPoints());
  std::string dealerPoints =
    std::to_string((int)blackJack.getDealer().getCardsPoints());

  std::map<BlackJack::GameRoundResult, std::string> messages = {
    { BlackJack::PLAYER_BUSTED, "Player busted. Dealer Wins" },
    { BlackJack::DEALER_BUSTED, "Dealer busted. Player Wins" },
    { BlackJack::PLAYER_WON,
      "Player won. Player:" + playerPoints + "Dealer:" + dealerPoints },
    { BlackJack::DEALER_WON,
      "Dealer won. Dealer:" + dealerPoints + " Player:" + playerPoints },
    { BlackJack::DRAW,
      "Draw. Dealer:" + dealerPoints + " Player:" + playerPoints },
  };
  std::cout << "-----Game Result-----" << std::endl
            << messages[blackJack.getWinner()] << std::endl;
}