#include <iostream>
#include <string>

using std::string;
int main() {
    int age{};
    string name;
    string gender;
    std::cout << "Type your name\n";
    std::getline(std::cin, name);
    std::cout << "Type your age\n";
    std::cin >> age;
    std::cout << "Type your gender\n";
    std::cin >> gender;
    std::cout << name <<" "<< age << " " << gender << "\n";
    return 0;
}
