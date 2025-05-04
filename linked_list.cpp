#include <iostream>
#include "List.h"

void displayMenu() {
    std::cout << "Menu:\n";
    std::cout << "1. Insert into List 1\n";
    std::cout << "2. Insert into List 2\n";
    std::cout << "3. Merge List 1 and List 2 into List 3\n";
    std::cout << "4. Display List 1\n";
    std::cout << "5. Display List 2\n";
    std::cout << "6. Display List 3\n";
    std::cout << "7. Exit\n";
}

int main() {
    List list1, list2, list3;
    int choice, value;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert into List 1: ";
                std::cin >> value;
                list1.insertAscending(value);
                break;
            case 2:
                std::cout << "Enter value to insert into List 2: ";
                std::cin >> value;
                list2.insertAscending(value);
                break;
            case 3:
                list3.merge(list1);
                list3.merge(list2);
                std::cout << "Merged List 3 created.\n";
                break;
            case 4:
                std::cout << "List 1: ";
                list1.display();
                break;
            case 5:
                std::cout << "List 2: ";
                list2.display();
                break;
            case 6:
                std::cout << "List 3: ";
                list3.display();
                break;
            case 7:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void List:: insertAscending(int value) {
  Node* newNode = new Node(value);
  if (!head || head->data > value) {
      newNode->next = head;
      head = newNode;
      return;
  }

  Node* current = head;
  while (current->next && current->next->data < value) {
      current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
}

void List::  merge(List& other) {
  Node* current1 = head;
  Node* current2 = other.gethead();
  List mergedList;

  while (current1 && current2) {
      if (current1->data < current2->data) {
          mergedList.insertAscending(current1->data);
          current1 = current1->next;
      } else {
          mergedList.insertAscending(current2->data);
          current2 = current2->next;
      }
  }

  while (current1) {
      mergedList.insertAscending(current1->data);
      current1 = current1->next;
  }

  while (current2) {
      mergedList.insertAscending(current2->data);
      current2 = current2->next;
  }

  
  head = mergedList.gethead();
}

void List:: display() const {
  Node* current = head;
  while (current) {
      std::cout << current->data << " ";
      current = current->next;
  }
  std::cout << std::endl;
}
};