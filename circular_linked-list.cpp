#include <iostream>
#include<stack>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList();
    void insertBeginning(int value);
    void insertEnd(int value);
    void insertPosition(int value, int position);
    void deleteBeginning();
    void deleteEnd();
    void deletePosition(int position);
    void search(int value);
    void display();
    ~CircularLinkedList();
};

int main() {
    CircularLinkedList cll;
    int choice, value, position;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Insert Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                cll.insertBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                cll.insertEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                cll.insertPosition(value, position);
                break;
            case 4:
                cll.deleteBeginning();
                break;
            case 5:
                cll.deleteEnd();
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                cll.deletePosition(position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                cll.search(value);
                break;
            case 8:
                cll.display();
                break;
            case 9:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}

CircularLinkedList::CircularLinkedList() : head(nullptr) {}

CircularLinkedList::~CircularLinkedList() {
    if (head == nullptr) return; // If the list is empty, nothing to delete

    Node* current = head;
    Node* nextNode;

    // Loop through the list and delete each node
    do {
        nextNode = current->next; // Store the next node
        delete current;           // Delete the current node
        current = nextNode;       // Move to the next node
    } while (current != head);

    head = nullptr; // Set head to nullptr to avoid dangling pointer
}



void CircularLinkedList::insertBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void CircularLinkedList::insertEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void CircularLinkedList::insertPosition(int value, int position) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (position == 1) {
        insertBeginning(value);
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void CircularLinkedList::deleteBeginning() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
    }
}

void CircularLinkedList::deleteEnd() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }
}

void CircularLinkedList::deletePosition(int position) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    if (position == 1) {
        deleteBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

void CircularLinkedList::search(int value) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    int position = 1;
    do {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    cout << "Value " << value << " not found in the list." << endl;
}

void CircularLinkedList::display() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    // Display forward
    cout << "List in forward order: ";
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;

    // Display reverse using a stack
    cout << "List in reverse order: ";
    stack<int> s;
    temp = head;
    do {
        s.push(temp->data);
        temp = temp->next;
    } while (temp != head);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}