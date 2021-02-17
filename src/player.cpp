
#include "player.hpp"
#include "cards.hpp"

void
Player::addCard(Cards::Card card)
{
  cards.push_back(card);
}

void
Player::emptyCards()
{ 
  cards.clear();
}

std::vector<Cards::Card>
Player::getCards()
{
  return cards;
}

unsigned char
Player::getCardsPoints()
{
  unsigned char points = 0;
  for (auto const& card : cards) {
    points += Cards::getCardValue(card);
  }
  return points;
}

std::string
Player::getName()
{
  return name;
}

bool
Player::isBetOnCards()
{
  return betOnCards;
}

void
Player::setBetOnCards(bool betOnCards)
{
  this->betOnCards = betOnCards;
}
