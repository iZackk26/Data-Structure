#include "Card.h"
#include <iostream>
#include <string>

using std::string;

class Player {
    public:
      string name;
      int age{};
      string mail;
      int score{};

      // Deck Maze
      Card cards[10];

      // Constructors
      Player() {
        name = "";
        age = 0;
        mail = "";
        score = 0;
      }

      Player(string name, int age, string mail) {
        this->name = name;
        this->age = age;
        this->mail = mail;
        this->score = 0;
      }

      // Methods
      void printMaze();

      void getMaze(Card *cards);

      int getMaxCard();

      void setUsedCard(int value);
};
