#include <iostream>
#include "scheduler.h"
using namespace std;

// Node structure for the circular linked list
struct Node {
    int time; // Time required for the process
    Node* next; // Pointer to the next node
};

// Global variables
Node* head = nullptr; // Head of the circular linked list
int timeSlot; // Fixed time slot for each process

// Function to insert a process into the circular linked list
void insertProcess(int processTime) {
    Node* newNode = new Node();
    newNode->time = processTime;

    if (head == nullptr) {
        // If the list is empty, create a new circular list
        head = newNode;
        head->next = head;
    } else {
        // Insert the new node at the end of the circular list
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    cout << "Process with time " << processTime << " inserted." << endl;
}

// Function to execute the round-robin scheduling
void execute() {
    if (head == nullptr) {
        cout << "No processes to execute." << endl;
        return;
    }

    // Remove the process at the head of the list
    Node* current = head;
    Node* prev = nullptr;

    // Find the last node to update its next pointer
    while (prev == nullptr || prev->next != head) {
        prev = current;
        current = current->next;
    }

    // Subtract the time slot from the process
    current->time -= timeSlot;

    if (current->time <= 0) {
        // Process has completed execution
        cout << "Process with remaining time " << (current->time + timeSlot) << " executed and removed." << endl;
        if (current == head && head->next == head) {
            // Only one process in the list
            delete current;
            head = nullptr;
        } else {
            // Remove the current node
            prev->next = current->next;
            if (current == head) {
                head = current->next;
            }
            delete current;
        }
    } else {
        // Reinsert the process at the end of the list
        cout << "Process with remaining time " << current->time << " reinserted." << endl;
        prev->next = current->next;
        current->next = head;
        head = current->next;
    }
}

// Main function
int main() {
    int choice, processTime;

    cout << "Enter the fixed time slot for each process: ";
    cin >> timeSlot;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Process\n";
        cout << "2. Execute\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the process time: ";
                cin >> processTime;
                insertProcess(processTime);
                break;
            case 2:
                execute();
                break;
            case 3:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}