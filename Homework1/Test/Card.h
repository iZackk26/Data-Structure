#include <iostream>
#ifndef CARD_H
#define CARD_H

using std::string;
class Card {

public:
  // Properties of the Class
  string symbol;
  int value;
  bool isUsed{false};
  bool throwCard{false};

  // Constructor
  
  // * Default Constructor
  Card() {
    symbol = " ";
    value = 0;
  }
  // * Args Constructor
  Card(string symbol, int value) {
    this->symbol = symbol;
    this->value = value;
  }
  friend std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.symbol << " " << card.value << " ";
    return os;
  }

};
#endif
