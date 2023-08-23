#include <iostream>
#include <string>

int power(int base, int exponent) {
  int result = 1;
  for (int i = 0; i < exponent; ++i) {
    result *= base;
  }
  return result;
}

int sum(int quantity) {
    int result = 0;
    for (int i = 0; i < quantity; ++i) {
        result += i;
    }
    return result;
}

int main() {
    int base{};
    int exponent{};
    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter exponent: ";
    std::cin >> exponent;
    std::cout << base << " ^ " << exponent << " = " << power(base, exponent) << "\n";
    std::cout << "Enter quantity: ";
    std::cin >> exponent;
    std::cout << "Sum of " << exponent << " = " << sum(exponent) << "\n";
    return 0;
}


