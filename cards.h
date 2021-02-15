#ifndef CARDS_H
#define CARDS_H

#include <string>

namespace Cards {

enum Card
{
  no_card = 0x00,
  clubs_ace = 0x01,
  clubs_two = 0x02,
  clubs_three = 0x03,
  clubs_four = 0x04,
  clubs_five = 0x05,
  clubs_six = 0x06,
  clubs_seven = 0x07,
  clubs_eight = 0x08,
  clubs_nine = 0x09,
  clubs_ten = 0x0A,
  clubs_jack = 0x0B,
  clubs_queen = 0x0C,
  clubs_king = 0x0D,
  diamonds_ace = 0x11,
  diamonds_two = 0x12,
  diamonds_three = 0x13,
  diamonds_four = 0x14,
  diamonds_five = 0x15,
  diamonds_six = 0x16,
  diamonds_seven = 0x17,
  diamonds_eight = 0x18,
  diamonds_nine = 0x19,
  diamonds_ten = 0x1A,
  diamonds_jack = 0x1B,
  diamonds_queen = 0x1C,
  diamonds_king = 0x1D,
  hearts_ace = 0x21,
  hearts_two = 0x22,
  hearts_three = 0x23,
  hearts_four = 0x24,
  hearts_five = 0x25,
  hearts_six = 0x26,
  hearts_seven = 0x27,
  hearts_eight = 0x28,
  hearts_nine = 0x29,
  hearts_ten = 0x2A,
  hearts_jack = 0x2B,
  hearts_queen = 0x2C,
  hearts_king = 0x2D,
  spades_ace = 0x31,
  spades_two = 0x32,
  spades_three = 0x33,
  spades_four = 0x34,
  spades_five = 0x35,
  spades_six = 0x36,
  spades_seven = 0x37,
  spades_eight = 0x38,
  spades_nine = 0x39,
  spades_ten = 0x3A,
  spades_jack = 0x3B,
  spades_queen = 0x3C,
  spades_king = 0x3D
};

std::string
getCardName(Card card);

unsigned char
getCardValue(Card card);

}

#endif
