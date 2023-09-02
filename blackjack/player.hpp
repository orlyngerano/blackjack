#pragma once

#include "cards.hpp"
#include <vector>

class Player
{
  std::string name;
  std::vector<Cards::Card> cards;
  bool betOnCards;

public:
  Player(std::string name)
    : name(name)
  {
    cards.reserve(4);
  }

  void addCard(Cards::Card card);

  void emptyCards();
  std::vector<Cards::Card> getCards();
  unsigned char getCardsPoints();

  std::string getName();
  bool isBetOnCards();
  void setBetOnCards(bool betOnCards);
};
