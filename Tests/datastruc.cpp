#include <iostream>
#include <string>

using std::string;

struct Persona{
    string nombre;
    int edad = 0;
    Persona *next;
    Persona(string nombre, int edad) {
        this->nombre = nombre;
        this->edad = edad;
        next = nullptr;
    }
};

void addBegin(string nombre, int edad, Persona *&head) {
    Persona *p = new Persona(nombre, edad);
    p->next = head;
    head = p;
}

void addMiddle(string nombre, int edad, Persona *&head, Persona *&middle) {
    Persona *p = new Persona(nombre, edad);
    head->next = p;
    p->next = middle;
}
int main() {
    std::cout << "Simple List\n";
    Persona *p1 = new Persona("Juan", 20);
    Persona *p2 = new Persona("Pedro", 30);

    p1->next = p2;
    addMiddle("Maria", 40, p1, p2);


    while (p1 != nullptr) {
        std::cout << p1->nombre << " " << p1->edad << "\n";
        p1 = p1->next;
    }


}
