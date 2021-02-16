#ifndef BLACKJACKCONSOLE_H
#define BLACKJACKCONSOLE_H

#include "blackjack.h"
#include "player.h"
#include <string>

class BlackJackConsole
{
  Player player;
  BlackJack blackJack;

public:
  BlackJackConsole(std::string playerName)
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