#include <iostream>
#include <string>

using std::string;

struct Node {
    int number;
    Node* next;
    // No args constructor
    Node() {
        number = 0;
        next = nullptr;
    }
    // Args constructor
    Node(int number) {
        this->number = number;
    }
};
