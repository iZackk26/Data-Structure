#include <cstdlib>
#include <iostream>
#include <random>
#include <string>

using std::string; // Esto se utiliza para no escribir std::string

int randomNumber(bool checker = false) {
  // Esta funcion obtiene un numero aleatorio entre 0 y 3 o entre 0 y 13,
  // dependiendo de si checker es true o false
  std::random_device rd;
  std::mt19937 gen(rd());
  if (checker) {
    std::uniform_int_distribution<> dist(0, 3);
    int numeroAleatorio = dist(gen);
    return numeroAleatorio;
  }
  std::uniform_int_distribution<> dist(0, 13);
  int numeroAleatorio = dist(gen);
  return numeroAleatorio;
}

int randomBigMaze() {
  // Esta funcion obtiene un numero aleatorio entre 1 y 52
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, 52);
  int numeroAleatorio = dist(gen);
  return numeroAleatorio;
}

class Card {
  // Esta clase representa una carta con sus atributos
public:
  std::string name;
  int value;
  bool isUsed;
  bool isThrown;
  Card(std::string name, int value) {
    this->name = name;
    this->value = value;
    this->isUsed = false;
    this->isThrown = false;
  }
  Card() {
    this->name = "";
    this->value = 0;
    this->isUsed = false;
    this->isThrown = false;
  }
  // Esto se utiliza para imprimir la carta en la consola con su nombre y valor,
  // para evitar escribir std::cout << card.name << card.value
  friend std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.name << card.value;
    return os;
  }
};

class Player {
  // Esta clase representa un jugador con sus atributos y metodos
public:
  string name;
  int age;
  string mail;
  int score;
  Card maze[10];

  // Constructores de la clase
  Player() { // Constructor por defecto
    name = "";
    age = 0;
    mail = "";
    score = 0;
  }
  Player(string name, int age, string mail,
         int score) { // Constructor con parametros.
    this->name = name;
    this->age = age;
    this->mail = mail;
    this->score = score;
  }
  // Methods
  void ObtenerMazo(Card *cards) {
    // Esta funcion obtiene un mazo de 10 cartas aleatorias y las guarda en el
    // atributo maze
    for (int i = 0; i < 10; i++) {
      int random = randomBigMaze();
      while (cards[random].isUsed) {
        random = randomBigMaze();
      }
      cards[random].isUsed = true;
      this->maze[i] = cards[random];
    }
    std::cout << "Mazo del jugador: " << this->name << std::endl;
    std::cout << "\n";
    this->printMaze();
    std::cout << "\n";
  }

  void printMaze() {
    for (int i = 0; i < 10; i++) { // Imprime el mazo del jugador
      std::cout << maze[i] << " ";
    }
  }
};

void resultados(Player arr[5]) { // Esta funcion imprime los resultados del juego ordenados por puntaje
  std::cout << "\nResults of the game" << std::endl;
  // Print the results sorted by score ascending
  int n = 5;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      // Compare scores and swap if needed
      if (arr[j].score < arr[j + 1].score) {
        Player temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    std::cout << arr[i].name << " " << arr[i].score << std::endl;
  }
}

void setCards(Card *cards) { // Esta funcion crea las 52 cartas del juego y las guarda en el arreglo cards
  string valueCard[13] = {"1", "2", "3",  "4", "5", "6", "7",
                          "8", "9", "10", "J", "Q", "K"};
  string simbolCard[4] = {"♣", "♥", "♦", "♠"};
  for (int i = 0; i < 52; i++) {
    cards[i].name = simbolCard[i / 13];
    cards[i].value = i % 13 + 1;
  }
}

void play(Player *players, Card *cards) { // Esta funcion ejecuta el juego, posee la logica del juego
  std::cout << "Bienvenido al Juego de Cartas" << std::endl;
  // Ciclo for para crear los jugadores, se utiliza de acuerdo al indice del arreglo players
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
    players[i].ObtenerMazo(cards);
    std::cout << "\n";
  }
  for (int i = 0; i < 10; i++) {
    std::cout << "\n";
    std::cout << "         Ronda " << i + 1 << std::endl;
    int maxCard = 0;
    int temp = 0;
    int indiceGanador = 0;
    bool empate = false;
    for (int j = 0; j < 5; j++) {
      if (players[j].maze[i].value > maxCard &&players[j].maze[i].isThrown == false) { // Condicional para determinar el ganador de la ronda
        maxCard = players[j].maze[i].value; // 5 == 5 // 12
        indiceGanador = j;
      } 
      else if (players[j].maze[i].value == maxCard && j != indiceGanador) {
        empate = true;
        temp = j;
      }
      std::cout << players[j].name << " tira la carta : " << players[j].maze[i] << std::endl;
      players[j].maze[i].isThrown = true;
    }
    if (empate && players[temp].maze[i].value == maxCard) {
      std::cout << "Hubo un empate en la ronda " << i + 1 << std::endl;
      std::cout << "\n";
      continue;
    } 
    else { 
      std::cout << "El ganador de la ronda es: " << players[indiceGanador].name<< std::endl;
      std::cout << "\n";
      players[indiceGanador].score += 1;
    }
  }
  // Se imprimen los resultados del juego
  resultados(players);
}

int main() {
  Card *cards = new Card[52];
  Player *players = new Player[5]; // Esto tiene 5 jugadores players[indice].score
  setCards(cards);
  play(players, cards);
  return 0;
}
