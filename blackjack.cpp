

#include "blackjack.h"
#include "cards.h"
#include "player.h"
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

  if (playerPoints > 21) {
    return GameRoundResult::PLAYER_BUSTED;
  } else if (dealerPoints > 21) {
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

  if (player.getCardsPoints() > 21 || dealer.getCardsPoints() > 21) {
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
  return (dealer.getCardsPoints() < DEALER_SOFTPOINTS) ? true : false;
}

void
BlackJack::setCardDeck()
{
  cardDeck.clear();

  cardDeck.push_back(Cards::Card::clubs_ace);
  cardDeck.push_back(Cards::Card::clubs_two);
  cardDeck.push_back(Cards::Card::clubs_three);
  cardDeck.push_back(Cards::Card::clubs_four);
  cardDeck.push_back(Cards::Card::clubs_five);
  cardDeck.push_back(Cards::Card::clubs_six);
  cardDeck.push_back(Cards::Card::clubs_seven);
  cardDeck.push_back(Cards::Card::clubs_eight);
  cardDeck.push_back(Cards::Card::clubs_nine);
  cardDeck.push_back(Cards::Card::clubs_ten);
  cardDeck.push_back(Cards::Card::clubs_jack);
  cardDeck.push_back(Cards::Card::clubs_queen);
  cardDeck.push_back(Cards::Card::clubs_king);
  cardDeck.push_back(Cards::Card::diamonds_ace);
  cardDeck.push_back(Cards::Card::diamonds_two);
  cardDeck.push_back(Cards::Card::diamonds_three);
  cardDeck.push_back(Cards::Card::diamonds_four);
  cardDeck.push_back(Cards::Card::diamonds_five);
  cardDeck.push_back(Cards::Card::diamonds_six);
  cardDeck.push_back(Cards::Card::diamonds_seven);
  cardDeck.push_back(Cards::Card::diamonds_eight);
  cardDeck.push_back(Cards::Card::diamonds_nine);
  cardDeck.push_back(Cards::Card::diamonds_ten);
  cardDeck.push_back(Cards::Card::diamonds_jack);
  cardDeck.push_back(Cards::Card::diamonds_queen);
  cardDeck.push_back(Cards::Card::diamonds_king);
  cardDeck.push_back(Cards::Card::hearts_ace);
  cardDeck.push_back(Cards::Card::hearts_two);
  cardDeck.push_back(Cards::Card::hearts_three);
  cardDeck.push_back(Cards::Card::hearts_four);
  cardDeck.push_back(Cards::Card::hearts_five);
  cardDeck.push_back(Cards::Card::hearts_six);
  cardDeck.push_back(Cards::Card::hearts_seven);
  cardDeck.push_back(Cards::Card::hearts_eight);
  cardDeck.push_back(Cards::Card::hearts_nine);
  cardDeck.push_back(Cards::Card::hearts_ten);
  cardDeck.push_back(Cards::Card::hearts_jack);
  cardDeck.push_back(Cards::Card::hearts_queen);
  cardDeck.push_back(Cards::Card::hearts_king);
  cardDeck.push_back(Cards::Card::spades_ace);
  cardDeck.push_back(Cards::Card::spades_two);
  cardDeck.push_back(Cards::Card::spades_three);
  cardDeck.push_back(Cards::Card::spades_four);
  cardDeck.push_back(Cards::Card::spades_five);
  cardDeck.push_back(Cards::Card::spades_six);
  cardDeck.push_back(Cards::Card::spades_seven);
  cardDeck.push_back(Cards::Card::spades_eight);
  cardDeck.push_back(Cards::Card::spades_nine);
  cardDeck.push_back(Cards::Card::spades_ten);
  cardDeck.push_back(Cards::Card::spades_jack);
  cardDeck.push_back(Cards::Card::spades_queen);
  cardDeck.push_back(Cards::Card::spades_king);

  shuffleDeck();
}

void
BlackJack::shuffleDeck()
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle(cardDeck.begin(), cardDeck.end(), std::default_random_engine(seed));
}