#include "Card.h"
#include "Player.h"
#include <iostream>
#include <random>
#include <string>

using std::string;

// Function Prototypes
int randomNumber();

// Class Player methods
void Player::printMaze() {
  for (int i = 0; i < 10; i++) {
    std::cout << cards[i];
  }
}
void Player::getMaze(Card *cards) {
    int random = randomNumber();
    
    
}

int Player::getMaxCard() {
  int max = 0;
  for (int i = 0; i < 10; i++) {
    if (this->cards[i].value > max) {
      max = this->cards[i].value;
    }
  }
  return max;
}
void Player::setUsedCard(int value) {
  for (int i = 0; i < 10; i++) {
    if (this->cards[i].value == value) {
      this->cards[i].isUsed = true;
    }
  }
}
// End of Player Functions

int randomNumber() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, 51);
  int numeroAleatorio = dist(gen);
  return numeroAleatorio;
}

void setCards(Card *cards) {
  string valueCard[13] = {"1", "2", "3",  "4", "5", "6", "7",
                          "8", "9", "10", "J", "Q", "K"};
  string simbolCard[4] = {"♣", "♥", "♦", "♠"};
  for (int i = 0; i < 52; i++) {
    cards[i].symbol = simbolCard[i / 13];
    cards[i].value = i % 13 + 1;
  }
}

void playCardGame(Card *globalCards, Player *players) {
  for (int i = 0; i < 5; i++) {
    std::cout << "\n";
    std::cout << "Jugador " << i + 1 << std::endl;
    std::cout << "Ingrese su nombre: ";
    std::cin >> players[i].name;
    std::cout << "Ingrese su edad: ";
    std::cin >> players[i].age;
    std::cout << "Ingrese su correo: ";
    std::cin >> players[i].mail;
    std::cout << "\n";
    players[i].getMaze(globalCards);
    std::cout << "\n";
  }
  // Ciclo for para jugar las 10 rondas del juego
  for (int i = 0; i < 10; i++) {
    std::cout << "\n";
    std::cout << "Ronda " << i + 1 << std::endl;
    int max = 0;
    int temp = 0;
    int winner = 0;
    bool empate = false;
    // Ciclo for para jugar cada ronda
    for (int j = 0; j < 5; j++) {
      if (players[j].getMaxCard() > max) {
        max = players[j].getMaxCard();
        winner = j;
      } else if (players[j].getMaxCard() == max &&
                 players[j].getMaxCard() != temp) {
        empate = true;
        temp = j;
      }
      std::cout << "Jugador " << j + 1 << " tira " << players[j].getMaxCard()
                << std::endl;
      players[j].setUsedCard(players[j].getMaxCard());
    }
    if (empate) {
      std::cout << "Draw Match " << std::endl;
    } else {
      std::cout << "El ganador de la ronda es el jugador "
                << players[winner].name << std::endl;
      players[winner].score++;
    }
  }
}

int main() {
  Card *globalCards = new Card[52];
  Player *players = new Player[5];
  int count = 0;
  while (count < 1000) {
      std::cout << randomNumber() << std::endl;
    count++;
  }
  setCards(globalCards);
  playCardGame(globalCards, players);
  return 0;
}
