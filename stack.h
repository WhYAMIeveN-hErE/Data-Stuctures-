#ifndef STACK_H
#define STACK_H

// Node structure for singly linked list
struct Node {
    char data;      // Data part
    Node* next;     // Pointer to the next node

    Node(char value); // Constructor
};

// Stack class using singly linked list
class Stack {
private:
    Node* top; // Pointer to the top node

public:
    Stack(); // Constructor to initialize the stack
    bool isEmpty(); // Check if the stack is empty
    void push(char value); // Push an element onto the stack
    char pop(); // Pop an element from the stack
    char peek(); // Peek at the top element of the stack
    ~Stack(); // Destructor to free memory
};

#endif // STACK_H