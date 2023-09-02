#include "blackjack.hpp"
#include "cards.hpp"
#include "player.hpp"
#include <algorithm>
#include <chrono>
#include <random>

void
BlackJack::endGame()
{
  state = State::GAME_END;
}

void
BlackJack::endGameRound()
{
  state = State::GAME_ROUND_END;
}

Player
BlackJack::getDealer()
{
  return dealer;
}

Player
BlackJack::getPlayer()
{
  return player;
}

BlackJack::State
BlackJack::getState()
{
  return state;
}

BlackJack::GameRoundResult
BlackJack::getWinner()
{
  unsigned char playerPoints = player.getCardsPoints();
  unsigned char dealerPoints = dealer.getCardsPoints();

  if (playerPoints > blackjack_winning_score) {
    return GameRoundResult::PLAYER_BUSTED;
  } else if (dealerPoints > blackjack_winning_score) {
    return GameRoundResult::DEALER_BUSTED;
  } else if (playerPoints > dealerPoints) {
    return GameRoundResult::PLAYER_WON;
  } else if (playerPoints < dealerPoints) {
    return GameRoundResult::DEALER_WON;
  } else {
    return GameRoundResult::DRAW;
  }
}

void
BlackJack::playerHitCard()
{
  if (state != State::PLAYER_TURN) {
    return;
  }

  Cards::Card card = getNextCardFromDeck();
  player.addCard(card);
  state = State::DEALER_TURN;

  dealersTurn();
}

void
BlackJack::playerStand()
{
  if (state != State::PLAYER_TURN) {
    return;
  }

  player.setBetOnCards(true);
  state = State::DEALER_TURN;

  dealersTurn();
}

void
BlackJack::startGame()
{
  setCardDeck();
  state = State::GAME_START;
}

void
BlackJack::startGameRound()
{

  player.emptyCards();
  dealer.emptyCards();
  player.setBetOnCards(false);
  dealer.setBetOnCards(false);

  state = State::GAME_ROUND_START;

  player.addCard(getNextCardFromDeck());
  dealer.addCard(getNextCardFromDeck());
  player.addCard(getNextCardFromDeck());
  dealer.addCard(getNextCardFromDeck());

  state = State::PLAYER_TURN;
}

void
BlackJack::dealerHitCard()
{
  dealer.addCard(getNextCardFromDeck());
}

void
BlackJack::dealersTurn()
{
  if (state != State::DEALER_TURN) {
    return;
  }

  if (isDealerWantToHit()) {
    dealerHitCard();
  } else {
    dealer.setBetOnCards(true);
  }

  if (player.getCardsPoints() > blackjack_winning_score ||
      dealer.getCardsPoints() > blackjack_winning_score) {
    endGameRound();
  } else {
    if (player.isBetOnCards() && dealer.isBetOnCards()) {
      endGameRound();
    } else {
      if (player.isBetOnCards()) {
        dealersTurn();
      } else {
        state = State::PLAYER_TURN;
      }
    }
  }
}

Cards::Card
BlackJack::getNextCardFromDeck()
{
  if (cardDeck.empty()) {
    setCardDeck();
  }
  Cards::Card card = cardDeck.front();
  cardDeck.erase(cardDeck.begin());
  return card;
}

bool
BlackJack::isDealerWantToHit()
{
  return dealer.getCardsPoints() < dealer_softpoints;
}

void
BlackJack::setCardDeck()
{
  cardDeck.clear();

  cardDeck.emplace_back(Cards::Card::clubs_ace);
  cardDeck.emplace_back(Cards::Card::clubs_two);
  cardDeck.emplace_back(Cards::Card::clubs_three);
  cardDeck.emplace_back(Cards::Card::clubs_four);
  cardDeck.emplace_back(Cards::Card::clubs_five);
  cardDeck.emplace_back(Cards::Card::clubs_six);
  cardDeck.emplace_back(Cards::Card::clubs_seven);
  cardDeck.emplace_back(Cards::Card::clubs_eight);
  cardDeck.emplace_back(Cards::Card::clubs_nine);
  cardDeck.emplace_back(Cards::Card::clubs_ten);
  cardDeck.emplace_back(Cards::Card::clubs_jack);
  cardDeck.emplace_back(Cards::Card::clubs_queen);
  cardDeck.emplace_back(Cards::Card::clubs_king);
  cardDeck.emplace_back(Cards::Card::diamonds_ace);
  cardDeck.emplace_back(Cards::Card::diamonds_two);
  cardDeck.emplace_back(Cards::Card::diamonds_three);
  cardDeck.emplace_back(Cards::Card::diamonds_four);
  cardDeck.emplace_back(Cards::Card::diamonds_five);
  cardDeck.emplace_back(Cards::Card::diamonds_six);
  cardDeck.emplace_back(Cards::Card::diamonds_seven);
  cardDeck.emplace_back(Cards::Card::diamonds_eight);
  cardDeck.emplace_back(Cards::Card::diamonds_nine);
  cardDeck.emplace_back(Cards::Card::diamonds_ten);
  cardDeck.emplace_back(Cards::Card::diamonds_jack);
  cardDeck.emplace_back(Cards::Card::diamonds_queen);
  cardDeck.emplace_back(Cards::Card::diamonds_king);
  cardDeck.emplace_back(Cards::Card::hearts_ace);
  cardDeck.emplace_back(Cards::Card::hearts_two);
  cardDeck.emplace_back(Cards::Card::hearts_three);
  cardDeck.emplace_back(Cards::Card::hearts_four);
  cardDeck.emplace_back(Cards::Card::hearts_five);
  cardDeck.emplace_back(Cards::Card::hearts_six);
  cardDeck.emplace_back(Cards::Card::hearts_seven);
  cardDeck.emplace_back(Cards::Card::hearts_eight);
  cardDeck.emplace_back(Cards::Card::hearts_nine);
  cardDeck.emplace_back(Cards::Card::hearts_ten);
  cardDeck.emplace_back(Cards::Card::hearts_jack);
  cardDeck.emplace_back(Cards::Card::hearts_queen);
  cardDeck.emplace_back(Cards::Card::hearts_king);
  cardDeck.emplace_back(Cards::Card::spades_ace);
  cardDeck.emplace_back(Cards::Card::spades_two);
  cardDeck.emplace_back(Cards::Card::spades_three);
  cardDeck.emplace_back(Cards::Card::spades_four);
  cardDeck.emplace_back(Cards::Card::spades_five);
  cardDeck.emplace_back(Cards::Card::spades_six);
  cardDeck.emplace_back(Cards::Card::spades_seven);
  cardDeck.emplace_back(Cards::Card::spades_eight);
  cardDeck.emplace_back(Cards::Card::spades_nine);
  cardDeck.emplace_back(Cards::Card::spades_ten);
  cardDeck.emplace_back(Cards::Card::spades_jack);
  cardDeck.emplace_back(Cards::Card::spades_queen);
  cardDeck.emplace_back(Cards::Card::spades_king);

  shuffleDeck();
}

void
BlackJack::shuffleDeck()
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(
    cardDeck.begin(), cardDeck.end(), std::default_random_engine(seed));
}