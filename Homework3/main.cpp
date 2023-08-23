#include "list.h"
#include <iostream>
#include <string>

using std::string;

Node *fillList(Node *list) {
  int arr[5] = {10, 10, 10, 5, 5};
  for (int i = 0; i < 5; i++) {
    if (list == nullptr) {
      list = new Node(arr[i]);
    } else {
      Node *node = new Node(arr[i]);
      node->next = list;
      list = node;
    }
  }
  return list;
}
Node *addAtEnd(Node *list, int value) {
  Node *node = new Node(value);
  Node *temp = list;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = node;
  return list;
}

void printList(Node *list) {
  while (list != nullptr) {
    std::cout << list->value << " ";
    list = list->next;
  }
  std::cout << std::endl;
}

int sumValues(Node *list) {
  int result = 0;
  while (list != nullptr) {
    result += list->value;
    list = list->next;
  }
  return result;
}

void determineBiggestList(Node *list1, Node *list2, Node *list3) {
  int sumList1 = sumValues(list1);
  int sumList2 = sumValues(list2);
  int sumList3 = sumValues(list3);
  if (sumList1 > sumList2 && sumList1 > sumList3) {
    std::cout << "List 1 is the biggest list\n" << std::endl;
  } else if (sumList2 > sumList1 && sumList2 > sumList3) {
    std::cout << "List 2 is the biggest list\n" << std::endl;
  } else if (sumList3 > sumList1 && sumList3 > sumList2) {
    std::cout << "List 3 is the biggest list\n" << std::endl;
  }
  // If there is a tie
  else if (sumList1 == sumList2 && sumList1 > sumList3) {
    std::cout << "List 1 and List 2 are the biggest lists\n" << std::endl;
  } else if (sumList1 == sumList3 && sumList1 > sumList2) {
    std::cout << "List 1 and List 3 are the biggest lists\n" << std::endl;
  } else if (sumList2 == sumList3 && sumList2 > sumList1) {
    std::cout << "List 2 and List 3 are the biggest lists\n" << std::endl;
  } else if (sumList1 == sumList2 && sumList1 == sumList3) {
    std::cout << "All lists are the same" << std::endl;
  }
}

bool checkInList(int arr[5], int value) {
  for (int i = 0; i < 5; i++) {
    if (arr[i] == value) {
      return true;
    }
  }
  return false;
}

void check3TimesRepeated(Node *list1, Node *list2) {
  int repetedValues[5];
  int idx = 0;
  while (list1 != nullptr) {
    int counter = 0;
    Node *temp = list2;
    while (temp != nullptr) {
      if (list1->value == temp->value) {
        counter++;
      }
      temp = temp->next;
    }
    if (counter == 3) {
      if (!checkInList(repetedValues, list1->value)) {
        repetedValues[idx] = list1->value;
        idx++;
        std::cout << list1->value << " is repeated 3 times" << std::endl;
      }
    }
    list1 = list1->next;
  }
}

int main() {
  Node *list1 = new Node;
  Node *list2 = new Node;
  Node *list3 = new Node;
  list1 = fillList(list1);
  list2 = fillList(list2);
  list3 = fillList(list3);
  printList(list1);
  printList(list2);
  printList(list3);
  Node *arr[3] = {list1, list2, list3};
  std::cout << "Type the list you want to add at the end:\n";
  std::cout << "1. List 1 | 2. List 2 | 3. List" << std::endl;
  int choice;
  int choice2;
  std::cin >> choice;
  if (choice > 3 || choice < 1) {
    std::cout << "Invalid choice!" << std::endl;
    return 0;
  }
  std::cout << "Type a value to add at the end:\n";
  int value;
  std::cin >> value;
  arr[choice - 1] = addAtEnd(arr[choice - 1], value);
  determineBiggestList(list1, list2, list3);
  std::cout << "Enter the lists you want to check for repeated values:\n";
  std::cout << "1. List 1 | 2. List 2 | 3. List" << std::endl;
  std::cin >> choice;
  std::cin >> choice2;
  check3TimesRepeated(arr[choice - 1], arr[choice2 - 1]);

  return 0;
}
