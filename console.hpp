#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "blackjack.hpp"
#include "player.hpp"
#include <string>

class Console
{
  Player player;
  BlackJack blackJack;

public:
  Console(std::string playerName)
    : player(playerName)
    , blackJack(player)
  {}

  void play();

private:
  bool askPlayerPlayToHitOrStand();

  bool askPlayerPlay();

  void showGreetings();

  void showExitMessage();

  void showPlayerCardMessage();

  void showGameRoundResultMessage();
};
#endif