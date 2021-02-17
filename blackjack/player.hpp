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
  {}

  void addCard(Cards::Card card);

  void emptyCards();
  std::vector<Cards::Card> getCards();
  unsigned char getCardsPoints();

  std::string getName();
  bool isBetOnCards();
  void setBetOnCards(bool betOnCards);
};
