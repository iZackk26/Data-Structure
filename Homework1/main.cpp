#include <iostream>
#include <string>
#include <string>
#include <random>
#include <cstdlib>

using std::string;

class Card { 
    public:
        string symbol;
        int value;
        bool isUsed{false};
        bool throwCard{false};
        
        // Constructors
        Card() {
            symbol = "";
            value = 0;
        }

        Card(string symbol, int value) {
            this->symbol = symbol;
            this->value = value;
        }
        friend std::ostream& operator<<(std::ostream& os, const Card& card) {
            os << card.symbol << " " << card.value;
            return os;
        }
};

// Card Deck

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

// End of Card Deck

//Prototypes
int randomNumber();
void showCards();

// End of Prototypes
class Player {
    public:
    string name;
    int age{};
    string mail;
    int score{};
    bool sorted{false};

    // Deck Maze
    Card cards[10]; // IMPPORTANT ARRAY OF CARDS

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
        void playerCards() {
            for (int i = 0; i < 10; i ++) {
                int random = randomNumber();
                if (allCards[random].isUsed == false) {
                    cards[i] = allCards[random];
                    allCards[random].isUsed = true;
                } 
                else {
                    i--;
                }
            }
            std::cout << "Cards of " << name << std::endl;
            showCards();
        }

        void showCards() {
            for (int i = 0; i < 10; i++) {
                std::cout << cards[i] << " ";
            }
            std::cout << std::endl;
        }
        int getMaxCard() {
            int max = 0;
            int index = 0;
            for (int i = 0; i < 10; i++) {
                if (cards[i].value > max && cards[i].throwCard == false) {
                    max = cards[i].value;
                    index = i;
                }
            }
            return index;
        }
};

// Functions

int randomNumber() {
  std::random_device rd;
  std::mt19937 gen(rd()); 
  std::uniform_int_distribution<> dist(0, 55);
  int numeroAleatorio = dist(gen);
  return numeroAleatorio;
}

void play(Player arr[5]) {
    /* // print player */
    /* for (int i = 0; i < 5; i++) { */
    /*     std::cout << arr[i].name << std::endl; */
    
    for (int i = 0; i < 10; i++) {
        std::cout << "\nRound " << i + 1 << std::endl;
        int biggestCard = 0;
        int index = 0;
        bool draw = false;
        // Find the biggest card with the index and print every card throwed
        for (int j = 0; j < 5; j++) {
            int maxCard = arr[j].getMaxCard();
            if (arr[j].cards[maxCard].value > biggestCard) {
                biggestCard = arr[j].cards[maxCard].value;
                index = j;
            // check if there is a Draw
            } 
            else if (arr[j].cards[maxCard].value == biggestCard && j != index) {
                draw = true;
                string name = arr[j].name;
            } 
            // Print the card throwed
            std::cout << arr[j].name << " throwed " << arr[j].cards[maxCard] << std::endl;
            arr[j].cards[maxCard].throwCard = true;

        }
        // Print the winner
        if (draw == false) {
            std::cout << "The winner is " << arr[index].name << std::endl;
            arr[index].score++;
        }
        // Print Draw match
        else {
            std::cout << "Draw match " << std::endl;
        }
    }
}



void results(Player arr[5]) {
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


// Main Function
int main() {
    Player arr[5];
    // Tests instances of Player class
    /*arr[0] = Player("Jorge", 20, "asdasd@");
    arr[0].playerCards();
    arr[1] = Player("Alejandro", 18, "dofgjd@");
    arr[1].playerCards();
    arr[2] = Player("Pepillo", 18, "dofgjd@");
    arr[2].playerCards();
    arr[3] = Player("Johitan Jue", 18, "dofgjd@");
    arr[3].playerCards();
    arr[4] = Player("Cheto", 18, "dofgjd@");
    arr[4].playerCards();*/

    for (int i = 0; i < 5; i++) {
        std::string name;
        int age;
        std::string mail;
        std::cout << "Enter the name of the player " << i + 1 << std::endl;
        std::cin >> name;
        std::cout << "Enter the age of the player " << i + 1 << std::endl;
        std::cin >> age;
        std::cout << "Enter the mail of the player " << i + 1 << std::endl;
        std::cin >> mail;
        arr[i] = Player(name, age, mail);
        arr[i].playerCards();
    }
    play(arr);
    results(arr);

}
