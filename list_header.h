#ifndef LIST_H
#define LIST_H

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class List {
private:
    Node* head;

    Node* gethead() {
        return head;
    }

public:
    List() : head(nullptr) {}

    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAscending(int value);

    void merge(List& other);

    void display();
};

#endif // LIST_H