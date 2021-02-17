#include "cards.hpp"
#include <string>

namespace Cards {

std::string
getCardName(Card card)
{
  std::string name;
  switch (card) {
    case clubs_ace:
      name = "ace of clubs";
      break;
    case clubs_two:
      name = "two of clubs";
      break;
    case clubs_three:
      name = "three of clubs";
      break;
    case clubs_four:
      name = "four of clubs";
      break;
    case clubs_five:
      name = "five of clubs";
      break;
    case clubs_six:
      name = "six of clubs";
      break;
    case clubs_seven:
      name = "seven of clubs";
      break;
    case clubs_eight:
      name = "eight of clubs";
      break;
    case clubs_nine:
      name = "nine of clubs";
      break;
    case clubs_ten:
      name = "ten of clubs";
      break;
    case clubs_jack:
      name = "jack of clubs";
      break;
    case clubs_queen:
      name = "queen of clubs";
      break;
    case clubs_king:
      name = "king of clubs";
      break;
    case diamonds_ace:
      name = "ace of diamonds";
      break;
    case diamonds_two:
      name = "two of diamonds";
      break;
    case diamonds_three:
      name = "three of diamonds";
      break;
    case diamonds_four:
      name = "four of diamonds";
      break;
    case diamonds_five:
      name = "five of diamonds";
      break;
    case diamonds_six:
      name = "six of diamonds";
      break;
    case diamonds_seven:
      name = "seven of diamonds";
      break;
    case diamonds_eight:
      name = "eight of diamonds";
      break;
    case diamonds_nine:
      name = "nine of diamonds";
      break;
    case diamonds_ten:
      name = "ten of diamonds";
      break;
    case diamonds_jack:
      name = "jack of diamonds";
      break;
    case diamonds_queen:
      name = "queen of diamonds";
      break;
    case diamonds_king:
      name = "king of diamonds";
      break;
    case hearts_ace:
      name = "ace of hearts";
      break;
    case hearts_two:
      name = "two of hearts";
      break;
    case hearts_three:
      name = "three of hearts";
      break;
    case hearts_four:
      name = "four of hearts";
      break;
    case hearts_five:
      name = "five of hearts";
      break;
    case hearts_six:
      name = "six of hearts";
      break;
    case hearts_seven:
      name = "seven of hearts";
      break;
    case hearts_eight:
      name = "eight of hearts";
      break;
    case hearts_nine:
      name = "nine of hearts";
      break;
    case hearts_ten:
      name = "ten of hearts";
      break;
    case hearts_jack:
      name = "jack of hearts";
      break;
    case hearts_queen:
      name = "queen of hearts";
      break;
    case hearts_king:
      name = "king of hearts";
      break;
    case spades_ace:
      name = "ace of spades";
      break;
    case spades_two:
      name = "two of spades";
      break;
    case spades_three:
      name = "three of spades";
      break;
    case spades_four:
      name = "four of spades";
      break;
    case spades_five:
      name = "five of spades";
      break;
    case spades_six:
      name = "six of spades";
      break;
    case spades_seven:
      name = "seven of spades";
      break;
    case spades_eight:
      name = "eight of spades";
      break;
    case spades_nine:
      name = "nine of spades";
      break;
    case spades_ten:
      name = "ten of spades";
      break;
    case spades_jack:
      name = "jack of spades";
      break;
    case spades_queen:
      name = "queen of spades";
      break;
    case spades_king:
      name = "king of spades";
      break;
    default:
      break;
  }
  return name;
}

unsigned char
getCardValue(Card card)
{
  unsigned char unmaskCard = 0x0f & card;
  return unmaskCard > 10 ? 10 : unmaskCard;
}

}