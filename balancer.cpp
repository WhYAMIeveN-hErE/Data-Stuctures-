#include <iostream>
#include <cstring>
#include "Stack.h"

using namespace std;

class ParenthesisChecker {
public:
    // Function to check if parentheses are balanced
    bool isBalanced(const string& str) {
        Stack stack; // Create a stack object

        for (char ch : str) {
            if (ch == '(') {
                stack.push(ch); // Push opening parenthesis onto stack
            } else if (ch == ')') {
                if (stack.isEmpty()) {
                    return false; // Unmatched closing parenthesis
                }
                stack.pop(); // Pop the matching opening parenthesis
            }
        }
        return stack.isEmpty(); // If stack is empty, parentheses are balanced
    }
};

int main() {
    ParenthesisChecker checker; // Create an instance of the checker
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string input;
                cout << "Enter a string of parentheses: ";
                cin >> input;
                if (checker.isBalanced(input)) {
                    cout << "The parentheses are balanced." << endl;
                } else {
                    cout << "The parentheses are not balanced." << endl;
                }
                break;
            }
            case 2:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}