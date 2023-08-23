#include <iostream>
#include <string>

using std::string;

struct DoubleList {
    int num = 0;
    DoubleList *sig;
    DoubleList *ant;
    DoubleList(int value) {
        num = value;
        sig = nullptr;
        ant = nullptr;
    }
};

DoubleList* insertBeginning(int x, DoubleList *list) {
    DoubleList *newNode = new DoubleList(x);

    if (list == nullptr) {
        list = newNode;
    } else {
        newNode->sig = list;
        list->ant = newNode;
        list = newNode;
    }
    return list;
}
void printList(DoubleList *list) {
    DoubleList *aux = list;
    while (aux != nullptr) {
        std::cout << aux->num << " ";
        aux = aux->sig;
    }
    std::cout << std::endl;
}

int main() {

    return 0;

}

