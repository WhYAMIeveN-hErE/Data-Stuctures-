#ifndef SCHEDULER_H // Include guard to prevent multiple inclusions
#define SCHEDULER_H

#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node {
    int time; // Time required for the process
    Node* next; // Pointer to the next node
};

// Global variables
extern Node* head; // Head of the circular linked list
extern int timeSlot; // Fixed time slot for each process

// Function prototypes
void insertProcess(int processTime); // Insert a process into the circular linked list
void execute(); // Execute the round-robin scheduling algorithm

#endif // SCHEDULER_H