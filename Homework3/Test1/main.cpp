#include "element.h" // This is the header file we created
#include "list.h"    // This is the header file we created
#include <iostream>
#include <random> // Se utiliza para crear los datos de cada lista
#include <string>

using std::string;

/* int randomNumber() { */
/*   std::random_device rd; */
/*   std::mt19937 gen(rd()); */
/*   std::uniform_int_distribution<> distribucion(1, 100); */

/*   return distribucion(gen); */
/* } */

void showList(Node *head) {
  Node *current = head;
  while (current != nullptr) {
    std::cout << current->number << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

void insertData(Node *list, int number) {
  Node *newNode = new Node(number);
  newNode->next = list;
  list = newNode;
}
void insertEnd(Node *list, int number) {
  Node *newNode = new Node(number);
  Node *current = list;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next = newNode;
}
void addInformationV1(Node *list) {
  for (int i = 0; i < 5; i++) {
    int arr[5] = {1, 2, 3, 3, 3};
    if (list == nullptr) {
      list = new Node(arr[i]);
      /* list = new Node(randomNumber()); */
    } else {
      insertData(list, arr[i]);
      /* insertData(list, randomNumber()); */
    }
  }
}
void userEndInformation(Node *list) {
  int number;
  std::cout << "Enter a number: ";
  std::cin >> number;
  insertEnd(list, number);
  showList(list);
}

void userChoice(Node *list1, Node *list2, Node *list3) {
  int listNumber;
  std::cout << "Type the number of the list you want to add a number to:\n";
  std::cout << "Options: 1. 2. 3.\n";
  std::cin >> listNumber;
  switch (listNumber) {
  case 1:
    userEndInformation(list1);
    break;
  case 2:
    userEndInformation(list2);
    break;
  case 3:
    userEndInformation(list3);
    break;
  default:
    std::cout << "Invalid number" << std::endl;
    break;
  }
}
int sumValues(Node *list) {
  int result = 0;
  while (list != nullptr) {
    result += list->number;
    list = list->next;
  }
  return result;
}

void determineBiggestList(Node *list1, Node *list2, Node *list3) {
  int sumList1 = sumValues(list1);
  int sumList2 = sumValues(list2);
  int sumList3 = sumValues(list3);
  if (sumList1 > sumList2 && sumList1 > sumList3) {
    std::cout << "List 1 is the biggest list" << std::endl;
  } else if (sumList2 > sumList1 && sumList2 > sumList3) {
    std::cout << "List 2 is the biggest list" << std::endl;
  } else if (sumList3 > sumList1 && sumList3 > sumList2) {
    std::cout << "List 3 is the biggest list" << std::endl;
  }
  // If there is a tie
  else if (sumList1 == sumList2 && sumList1 > sumList3) {
    std::cout << "List 1 and List 2 are the biggest lists" << std::endl;
  } else if (sumList1 == sumList3 && sumList1 > sumList2) {
    std::cout << "List 1 and List 3 are the biggest lists" << std::endl;
  } else if (sumList2 == sumList3 && sumList2 > sumList1) {
    std::cout << "List 2 and List 3 are the biggest lists" << std::endl;
  } else if (sumList1 == sumList2 && sumList1 == sumList3) {
    std::cout << "All lists are the same" << std::endl;
  }
}

int main() {
  // Creating List
  Node *list1 = nullptr;
  Node *list2 = nullptr;
  Node *list3 = nullptr;
  addInformationV1(list1);
  addInformationV1(list2);
  addInformationV1(list3);
  // Showing list1
  std::cout << "List 1: ";
  showList(list1);
  // Showing list2
  std::cout << "List 2: ";
  showList(list2);
  // Showing list3
  std::cout << "List 3: ";
  showList(list3);
  userChoice(list1, list2, list3);
  determineBiggestList(list1, list2, list3);

  return 0;
}
