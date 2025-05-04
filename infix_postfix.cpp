#include <iostream>
#include <cstring>
#include <cctype>
#include "Stack.h"

using namespace std;

class InfixPostfixConverter {
private:
    char infix[100]; // Array to store infix expression
    char postfix[100]; // Array to store postfix expression

    // Function to check precedence of operators
    int precedence(char op) {
        if (op == '=')
            return 1;
        if (op == '+' || op == '-')
            return 2;
        if (op == '*' || op == '/')
            return 3;
        return 0; // For non-operators
    }

    // Function to check if the character is an operator
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '=';
    }

public:
    // Function to get infix expression
    void getInfix() {
        cout << "Enter a valid infix expression: ";
        cin.ignore(); // Clear the input buffer
        cin.getline(infix, 100); // Get the infix expression
    }

    // Function to convert infix to postfix
    void convertInfixToPostfix() {
        Stack stack; // Create a stack object
        int j = 0; // Index for postfix array

        for (int i = 0; infix[i] != '\0'; i++) {
            if (isalnum(infix[i])) { // If the character is an operand
                postfix[j++] = infix[i]; // Add it to postfix
            } else if (infix[i] == '(') {
                stack.push(infix[i]); // Push '(' onto stack
            } else if (infix[i] == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix[j++] = stack.pop(); // Pop until '('
                }
                stack.pop(); // Pop the '('
            } else if (isOperator(infix[i])) {
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(infix[i])) {
                    postfix[j++] = stack.pop(); // Pop operators from stack
                }
                stack.push(infix[i]); // Push the current operator
            }
        }

        // Pop all the operators from the stack
        while (!stack.isEmpty()) {
            postfix[j++] = stack.pop();
        }
        postfix[j] = '\0'; // Null-terminate the postfix expression

        cout << "Postfix expression: " << postfix << endl;
    }

    // Function to evaluate postfix expression
    int evaluatePostfix() {
        Stack stack; // Create a stack object
        for (int i = 0; postfix[i] != '\0'; i++) {
            if (isalnum(postfix[i])) { // If the character is an operand
                stack.push(postfix[i]); // Push operand onto stack
            } else if (isOperator(postfix[i])) {
                int operand2 = stack.pop() - '0'; // Pop top two operands
                int operand1 = stack.pop() - '0';
                int result;

                // Perform the operation
                switch (postfix[i]) {
                    case '+': result = operand1 + operand2; break;
                    case '-': result = operand1 - operand2; break;
                    case '*': result = operand1 * operand2; break;
                    case '/': result = operand1 / operand2; break;
                    case '=': result = operand2; break; // Assignment operator
                    default: result = 0; break;
                }
                stack.push(result + '0'); // Push result back to stack
            }
        }
        return stack.pop() - '0'; // Return the final result
    }
};

int main() {
  InfixPostfixConverter converter; // Create an instance of the converter
  int choice;

  do {
      cout << "\nMenu:\n";
      cout << "1. Get Infix\n";
      cout << "2. Convert Infix to Postfix\n";
      cout << "3. Evaluate Postfix\n";
      cout << "4. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice) {
          case 1:
              converter.getInfix(); // Get infix expression
              break;
          case 2:
              converter.convertInfixToPostfix(); // Convert infix to postfix
              break;
          case 3:
              {
                  int result = converter.evaluatePostfix(); // Evaluate postfix expression
                  cout << "Result of postfix evaluation: " << result << endl;
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