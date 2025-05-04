/* Write a separate C++ menu-driven program to implement Tree ADT using a binary search tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations, 
 
1. Insert 
2. Preorder 
3. Inorder 
4. Postorder 
5. Search 
6. Exit 


#include<cstdio>
#include<cstdlib>
#include<cstdbool>

class Bst{
    private:
    typedef struct tree{
        int data;
        struct tree* left;
        struct tree* right;
    }bst;
    bst* root;
    public:
    Bst(){
        root = NULL;
        }
    ~Bst(){
        delete(root);
    }
    void insert(int data);
    void inorder();
    void preorder();
    void postorder();
    void search(int data);

};

int main(){
    return 0;
}

void Bst::insert(int data){
    bst* newnode = new bst;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if(root == NULL){
        root = newnode;
        }
    else{
        insert(data);
        }
}
*/
#include <iostream>
#include <limits>
using namespace std;

// Node structure for Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Tree ADT class
class BinarySearchTree {
private:
    Node* root;

    // Private helper methods
    Node* insertRecursive(Node* currentNode, int value);
    void preorderRecursive(Node* currentNode);
    void inorderRecursive(Node* currentNode);
    void postorderRecursive(Node* currentNode);
    Node* searchRecursive(Node* currentNode, int value);
    void deleteTree(Node* currentNode);

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Destructor
    ~BinarySearchTree() {
        deleteTree(root);
    }

    // Public interface methods
    void insert(int value);
    void preorder();
    void inorder();
    void postorder();
    bool search(int value);
};

// Private helper method implementations
Node* BinarySearchTree::insertRecursive(Node* currentNode, int value) {
    if (currentNode == nullptr) {
        return new Node(value);
    }

    if (value < currentNode->data) {
        currentNode->left = insertRecursive(currentNode->left, value);
    } else if (value > currentNode->data) {
        currentNode->right = insertRecursive(currentNode->right, value);
    } else {
        cout << "Value " << value << " already exists in the tree." << endl;
    }

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

Node* BinarySearchTree::searchRecursive(Node* currentNode, int value) {
    if (currentNode == nullptr || currentNode->data == value) {
        return currentNode;
    }

    if (value < currentNode->data) {
        return searchRecursive(currentNode->left, value);
    } else {
        return searchRecursive(currentNode->right, value);
    }
}

void BinarySearchTree::deleteTree(Node* currentNode) {
    if (currentNode == nullptr) return;

    deleteTree(currentNode->left);
    deleteTree(currentNode->right);
    delete currentNode;
}

// Public method implementations
void BinarySearchTree::insert(int value) {
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

bool BinarySearchTree::search(int value) {
    Node* result = searchRecursive(root, value);
    return result != nullptr;
}

// Main function with menu
int main() {
    BinarySearchTree bst;
    int choice, value;

    do {
        cout << "\n----- BINARY SEARCH TREE OPERATIONS -----" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Preorder Traversal" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Postorder Traversal" << endl;
        cout << "5. Search" << endl;
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
                cout << "Enter value to insert: ";
                if (cin >> value) {
                    bst.insert(value);
                    cout << "Value " << value << " inserted successfully." << endl;
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid integer." << endl;
                }
                break;

            case 2:
                bst.preorder();
                break;

            case 3:
                bst.inorder();
                break;

            case 4:
                bst.postorder();
                break;

            case 5:
                cout << "Enter value to search: ";
                if (cin >> value) {
                    if (bst.search(value)) {
                        cout << "Value " << value << " found in the tree." << endl;
                    } else {
                        cout << "Value " << value << " not found in the tree." << endl;
                    }
                } else {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid integer." << endl;
                }
                break;

            case 6:
                cout << "Exit" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}