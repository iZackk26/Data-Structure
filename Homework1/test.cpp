#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
using std::string;

// Card Class
class Card {
public:
  string value;
  int number;
  bool isUsed{false};
  bool thrown{false};
  Card(string value, int number) {
    this->value = value;
    this->number = number;
  }
  Card() {
    this->value = "";
    this->number = 0;
  }
  friend std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.value << card.number;
    return os;
  }
};

// All cards
Card allCards[56] = {
    Card("♣", 1),  Card("♣", 2),  Card("♣", 3),  Card("♣", 4),  Card("♣", 5),
    Card("♣", 6),  Card("♣", 7),  Card("♣", 8),  Card("♣", 9),  Card("♣", 10),
    Card("♣", 11), Card("♣", 12), Card("♣", 13), Card("♣", 14), Card("♦", 1),
    Card("♦", 2),  Card("♦", 3),  Card("♦", 4),  Card("♦", 5),  Card("♦", 6),
    Card("♦", 7),  Card("♦", 8),  Card("♦", 9),  Card("♦", 10), Card("♦", 11),
    Card("♦", 12), Card("♦", 13), Card("♦", 14), Card("♥", 1),  Card("♥", 2),
    Card("♥", 3),  Card("♥", 4),  Card("♥", 5),  Card("♥", 6),  Card("♥", 7),
    Card("♥", 8),  Card("♥", 9),  Card("♥", 10), Card("♥", 11), Card("♥", 12),
    Card("♥", 13), Card("♥", 14), Card("♠", 1),  Card("♠", 2),  Card("♠", 3),
    Card("♠", 4),  Card("♠", 5),  Card("♠", 6),  Card("♠", 7),  Card("♠", 8),
    Card("♠", 9),  Card("♠", 10), Card("♠", 11), Card("♠", 12), Card("♠", 13),
    Card("♠", 14)};

// Funcion that retuns a random number between 0 and 56
int randomNumber() {
  std::random_device rd;
  std::mt19937 gen(rd()); // El motor Mersenne Twister es comúnmente utilizado
  // Crear la distribución para el rango 0 a 56
  std::uniform_int_distribution<> dist(0, 55);
  // Obtener un número aleatorio del rango especificado
  int numeroAleatorio = dist(gen);
  return numeroAleatorio;
}

// Class Person
class Person {
public:
  string name;
  int age;
  string mail;
  Card cards[10];
  int points{0};
  // No-args Constructor
  Person() {
    this->name = "Guest";
    this->age = 0;
    this->mail = "guest@unkown.com";
    this->points = 0;
  }
  // Args constructor
  Person(string name, int age, string mail) {
    this->name = name;
    this->age = age;
    this->mail = mail;
  }

  int biggestCard() {
    int biggest = 0;
    int index = 0;
    for (int i = 0; i < 10; i++) {
      if (cards[i].number > biggest) {
        biggest = cards[i].number;
        index = i;
      }
    }
    return index;
  }
  // Throw card
  int throwCard(int index) {
    Card *card = &cards[index];
    if (card->thrown) {
      std::cout << "Card already thrown!\n";
      return -1;
    }
    std::cout << "Throwing card " << card << std::endl;
    card->thrown = true;
    return card->number;
  }

  void roundWinner() {
    std::cout << "Round winner: " << name << "\n";
    points++;
  }
  void setCards() {
    for (int i = 0; i < 10; i++) {
      int random = randomNumber();
      if (allCards[random].isUsed) {
        i--;
        continue;
      }
      this->cards[i] = allCards[random];
      allCards[random].isUsed = true;
      std::cout << cards[i] << " "; // Debug
    }
    std::cout << "Cards set for " << name << std::endl;
  }
};
Person personRegister(int index) {
  string name;
  int age{};
  string mail;
  std::cout << "Welcome to the card person register!" << std::endl;
  std::cout << "Player " << index << std::endl;
  std::cout << "Enter your name:\n";
  std::cin >> name;
  std::cout << "Enter your age:\n";
  std::cin >> age;
  std::cout << "Enter your mail:\n";
  std::cin >> mail;
  std::cout << "Name " << name << " Age " << age << " Mail " << mail << "\n";
  Person person{name, age, mail};
  person.setCards();
  return person;
}

void play(Person arr[3]) {
    std::cout << "Playing...\n";
    for (int i = 0; i < 10; i++) {
        std::cout << "Round " << i << "\n";
        int biggest = 0;
        int index = 0;
        for (int i = 0; i < 3; i++) {
            int card = arr[i].throwCard(arr[i].biggestCard());
            if (card > biggest) {
            biggest = arr[i].cards[i].number;
            index = i;
            }
        }
        arr[index].roundWinner();
        
      /* if (arr[i].cards[i].number == biggest) { */
      /*   std::cout << "Draw!\n"; */
      /*   continue; */
      /* } */
  }
}

int main() {
  Person arr[3];
  int choice{};
  std::cout << "Welcome to the card game!" << std::endl;
  std::cout << "\n1. Play" << std::endl;
  std::cout << "2. Exit" << std::endl;
  std::cout << "Enter your choice: ";
  std::cin >> choice;
  switch (choice) {
  case 1:
    std::cout << "Starting game..." << std::endl;
    for (int i = 0; i < 3; i++) {
      arr[i] = personRegister(i + 1);
      std::cout << "\n";
    }
    play(arr);
  case 2:
    std::cout << "Exiting..." << std::endl;
    break;
  default:
    std::cout << "Invalid choice!" << std::endl;
    break;
  }

  return 0;
}
