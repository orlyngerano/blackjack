#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "cards.h"
#include "player.h"

class BlackJack
{

public:
  enum GameRoundResult
  {
    PLAYER_BUSTED,
    DEALER_BUSTED,
    PLAYER_WON,
    DEALER_WON,
    DRAW
  };

  enum State
  {
    GAME_START,
    GAME_END,
    GAME_ROUND_START,
    GAME_ROUND_END,
    PLAYER_TURN,
    DEALER_TURN
  };

  BlackJack(Player player)
    : dealer("Anthony")
    , player(player)
    , state(GAME_START)
  {}

  void endGame();

  void endGameRound();

  Player getDealer();

  Player getPlayer();

  State getState();

  GameRoundResult getWinner();

  void playerHitCard();

  void playerStand();

  void startGame();

  void startGameRound();

private:
  State state;
  Player dealer;
  Player player;
  std::vector<Cards::Card> cardDeck;
  unsigned char const DEALER_SOFTPOINTS = 17;

  void dealerHitCard();

  void dealersTurn();

  Cards::Card getNextCardFromDeck();

  bool isDealerWantToHit();

  void setCardDeck();

  void shuffleDeck();
};

#endif