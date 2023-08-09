#include <iostream>
#include <string>
#include <random>
#include "char.h"

using std::string;

// Int Array randomly filled
int firstArray[10]; // 1.
char secondArray[8]; // 2.
int thirdArray[10][8]; // 3.
string fourthArray[2][2]; // 4.
Array arr[8];
int Array::count = 0;

// Function Prototypes
void fillArrayOfInts(int *arr[]);
void fillArrayOfChars(char *arr[]);
void fillArrayOfInts2D(int *arr[10][8]);
int randomInt(int min, int max);
void printArray(int *arr[]);


// Function Definitions

int randomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(generator);
}

void fillFirstArray(int arr[]) {
    for (int i = 0; i < 10; i++) {
        int randomNumer = randomInt(1, 30);
        arr[i] = randomNumer;
    }
}

void inputOfCharacters(char arr[]) {
    for (int i = 0; i < 8; i++) {
        std::cout << "Enter a character: ";
        std::cin >> arr[i];
    }
}

void setArray(Array arr[], char arr2[]) {
    for (int i = 0; i < 8; i++) {
        arr[i].setchar(arr2[i]);
    }
}


void fillArray2D(int arr[10][8], int arr2[10]) {
    for (int i = 0; i < 10; i++) {
        int index = 1;
        arr[i][0] = arr2[i];
        for (int j = 1; j < 8; j++) { 
            arr[i][j] = arr2[index];
            index++;
        }
    }
}
int stringIteration(string something, Array arr[]) {
    int count = 0;
    for (int i = 0; i < something.length(); i++) {
        for (int j = 0; j < 8; j++) {
            if (something[i] == arr[j].name){
                arr[j].incrementCount();
                count++;
            }
        }
    }
    return count;
}

void biggestString(string arr[2][2], Array arr2[]) {
    int biggest = 0;
    int row = 0;
    int column = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 ; j++) {
            int temp = stringIteration(arr[i][j], arr2);
            if (temp > biggest) {
                biggest = temp;
                row = i;
                column = j;
            }
        }
    }
    std::cout << "The biggest string is: " << arr[row][column] << std::endl;
}


void fillArrayStrings(string arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        std::cout << "Row " << i << std::endl;
        std::cout << "Enter a string: ";
        std::cin >> arr[i][0];
        for (int j = 1; j < 2; j++) {
            std::cout << "Column " << j << std::endl;
            std::cout << "Enter a string: ";
            std::cin >> arr[i][j];
        }
    }
    std::cout << std::endl;

}

// Overloaded Functions

void printArray(Array arr[]) {
    for (int i = 0; i < 8; i++) {
        std::cout << arr[i] << std::endl;
    }
}
void printArray(int arr[]) {
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void printArray(char arr[]) {
    for (int i = 0; i < 8; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void printArray(int arr[10][8]) {
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i][0] << " ";
        for (int j = 1; j < 8; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void printArray(string arr[2][2]) {
    for (int i = 0; i < 2; i++) {
        std::cout << arr[i][0] << " ";
        for (int j = 1; j < 2; j++) {
            std::cout << arr[i][j] << " ";
        }
    }
    std::cout << std::endl;
}

// End of Overloaded Functions

int main() {
    bool running = true;
    while (running) {
        std::cout << "\n";
        std::cout << "Welcome to the Assigment 2" << std::endl;
        std::cout << "Enter the option that you want to run: " << std::endl;
        std::cout << "1.Ints and Randoms\n2.Chars and Strings\n3.Exit" << std::endl;
        int option;
        std::cin >> option;
        switch (option) {
            case 1: {
                fillFirstArray(firstArray);
                printArray(firstArray);
                std::cout << std::endl;
                fillArray2D(thirdArray, firstArray);
                printArray(thirdArray);

                break;
            }
            case 2: {
                inputOfCharacters(secondArray);
                setArray(arr, secondArray);
                printArray(arr);
                fillArrayStrings(fourthArray);
                printArray(fourthArray);
                biggestString(fourthArray, arr);
                break;
            }
            case 3: {
                std::cout << "Exiting..." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid option" << std::endl;
                break;
            }
        }
        if (option == 3) {
            break;
        }
    }
}
