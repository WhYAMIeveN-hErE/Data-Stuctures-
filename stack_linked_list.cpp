#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    char data;      // Data part
    Node* next;     // Pointer to the next node

    Node(char value) : data(value), next(nullptr) {} // Constructor
};

// Stack class using singly linked list
class Stack {
private:
    Node* top; // Pointer to the top node

public:
    Stack() : top(nullptr) {} // Constructor to initialize the stack

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr; // Stack is empty if top is nullptr
    }

    // Function to push an element onto the stack
    void push(char value) {
        Node* newNode = new Node(value); // Create a new node
        newNode->next = top; // Link new node to the previous top
        top = newNode; // Update top to the new node
        cout << value << " pushed onto stack." << endl;
    }

    // Function to pop an element from the stack
    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack." << endl;
            return '\0'; // Return null character if stack is empty
        } else {
            char poppedValue = top->data; // Get the top value
            Node* temp = top; // Temporary pointer to delete the top node
            top = top->next; // Update top to the next node
            delete temp; // Delete the old top node
            return poppedValue; // Return the popped value
        }
    }

    // Function to peek at the top element of the stack
    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek." << endl;
            return '\0'; // Return null character if stack is empty
        } else {
            return top->data; // Return the top value
        }
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop(); // Pop all elements to free memory
        }
    }
};

int main() {
    Stack stack; // Create a stack object
    int choice;
    char value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                value = stack.pop();
                if (value != '\0') {
                    cout << value << " popped from stack." << endl;
                }
                break;
            case 3:
                value = stack.peek();
                if (value != '\0') {
                    cout << "Top element is: " << value << endl;
                }
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}