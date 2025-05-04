#include <iostream>
using namespace std;

class Stack {
private:
    char arr[5]; // Stack array of size 5
    int top;     // Index of the top element

public:
    Stack() : top(-1) {} // Constructor to initialize the stack

    // Function to check if the stack is full
    bool isFull() {
        return top == 4; // Stack is full if top is at index 4
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1; // Stack is empty if top is -1
    }

    // Function to push an element onto the stack
    void push(char value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value; // Increment top and add value
            cout << value << " pushed onto stack." << endl;
        }
    }

    // Function to pop an element from the stack
    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack." << endl;
            return '\0'; // Return null character if stack is empty
        } else {
            return arr[top--]; // Return top value and decrement top
        }
    }

    // Function to peek at the top element of the stack
    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot peek." << endl;
            return '\0'; // Return null character if stack is empty
        } else {
            return arr[top]; // Return the top value
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