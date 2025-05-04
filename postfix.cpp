#include <iostream>
#include <limits>
#include <stack>
#include <string>
#include <cctype> // for isdigit
using namespace std;

// Node structure for Binary Search Tree
struct Node {
    string data; // Change to string to accommodate operators
    Node* left;
    Node* right;

    // Constructor
    Node(string value) : data(value), left(nullptr), right(nullptr) {}
};

// Tree ADT class
class BinarySearchTree {
private:
    Node* root;

    // Private helper methods
    Node* insertRecursive(Node* currentNode, string value);
    void preorderRecursive(Node* currentNode);
    void inorderRecursive(Node* currentNode);
    void postorderRecursive(Node* currentNode);
    Node* searchRecursive(Node* currentNode, string value);
    void deleteTree(Node* currentNode);
    Node* constructExpressionTree(const string& postfix);

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Destructor
    ~BinarySearchTree() {
        deleteTree(root);
    }

    // Public interface methods
    void insert(string value);
    void preorder();
    void inorder();
    void postorder();
    bool search(string value);
    void constructExpressionTreeFromPostfix(const string& postfix);
};

// Private helper method implementations
Node* BinarySearchTree::insertRecursive(Node* currentNode, string value) {
    if (currentNode == nullptr) {
        return new Node(value);
    }

    // This method is not used for expression trees, but kept for compatibility
    return currentNode;
}

void BinarySearchTree::preorderRecursive(Node* currentNode) {
    if (currentNode == nullptr) return;

    cout << currentNode->data << " ";
    preorderRecursive(currentNode->left);
    preorderRecursive(currentNode->right);
}

void BinarySearchTree::inorderRecursive(Node* currentNode) {
    if (currentNode == nullptr) return;

    inorderRecursive(currentNode->left);
    cout << currentNode->data << " ";
    inorderRecursive(currentNode->right);
}

void BinarySearchTree::postorderRecursive(Node* currentNode) {
    if (currentNode == nullptr) return;

    postorderRecursive(currentNode->left);
    postorderRecursive(currentNode->right);
    cout << currentNode->data << " ";
}

Node* BinarySearchTree::searchRecursive(Node* currentNode, string value) {
    if (currentNode == nullptr || currentNode->data == value) {
        return currentNode;
    }

    // This method is not used for expression trees, but kept for compatibility
    return nullptr;
}

void BinarySearchTree::deleteTree(Node* currentNode) {
    if (currentNode == nullptr) return;

    deleteTree(currentNode->left);
    deleteTree(currentNode->right);
    delete currentNode;
}

// Public method implementations
void BinarySearchTree::insert(string value) {
    root = insertRecursive(root, value);
}

void BinarySearchTree::preorder() {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }
    cout << "Preorder traversal: ";
    preorderRecursive(root);
    cout << endl;
}

void BinarySearchTree::inorder() {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }
    cout << "Inorder traversal: ";
    inorderRecursive(root);
    cout << endl;
}

void BinarySearchTree::postorder() {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }
    cout << "Postorder traversal: ";
    postorderRecursive(root);
    cout << endl;
}

bool BinarySearchTree::search(string value) {
    Node* result = searchRecursive(root, value);
    return result != nullptr;
}

// Method to construct expression tree from postfix expression
void BinarySearchTree::constructExpressionTreeFromPostfix(const string& postfix) {
    stack<Node*> stack;
    for (char ch : postfix) {
        if (isspace(ch)) continue; // Skip spaces

        string token(1, ch); // Convert char to string
        if (isdigit(ch)) { // If the character is a digit
            stack.push(new Node(token));
        } else { // If the character is an operator
            Node* right = stack.top(); stack.pop();
            Node* left = stack.top(); stack.pop();
            Node* operatorNode = new Node(token);
            operatorNode->left = left;
            operatorNode->right = right;
            stack.push(operatorNode);
        }
    }
    root = stack.top(); // The root of the expression tree
}

// Main function with menu
int main() {
    BinarySearchTree bst;
    int choice;
    string postfix;

    do {
        cout << "\n----- EXPRESSION TREE OPERATIONS -----" << endl;
        cout << "1. Postfix Expression" << endl;
        cout << "2. Construct Expression Tree" << endl;
        cout << "3. Preorder" << endl;
        cout << "4. Inorder" << endl;
        cout << "5. Postorder" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        // Input validation
        if (!(cin >> choice)) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter a valid postfix expression (e.g., 23*54*+): ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, postfix);
                break;

            case 2:
                if (postfix.empty()) {
                    cout << "Please enter a postfix expression first." << endl;
                } else {
                    bst.constructExpressionTreeFromPostfix(postfix);
                    cout << "Expression tree constructed successfully." << endl;
                }
                break;

            case 3:
                bst.preorder();
                break;

            case 4:
                bst.inorder();
                break;

            case 5:
                bst.postorder();
                break;

            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}