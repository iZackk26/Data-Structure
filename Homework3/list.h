#include <iostream>
#include <string>

using std::string;

struct Node {
    int value;
    Node* next;
    // No args constructor
    Node() {
        value = 0;
        next = nullptr;
    }
    // Args constructor
    Node(int number) {
        this->value = number;
    }
};
