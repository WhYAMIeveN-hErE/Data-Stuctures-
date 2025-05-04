#include <iostream>
#include <vector>

class HashTable {
private:
    std::vector<int> table;
    int capacity;
    int size;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    HashTable(int cap) : capacity(cap), size(0) {
        table.resize(capacity, -1); // Initialize the table with -1 (indicating empty slots)
    }

    void insert(int key) {
        if (size >= capacity) {
            std::cout << "Hash table is full. Cannot insert " << key << std::endl;
            return;
        }

        int index = hashFunction(key);
        int i = 0; // Quadratic probing index

        while (table[index] != -1) { // Quadratic probing
            index = (hashFunction(key) + i * i) % capacity;
            i++;
        }
        table[index] = key;
        size++;
        std::cout << "Inserted " << key << " into the hash table." << std::endl;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        int i = 0; // Quadratic probing index

        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1; // Mark as deleted
                size--;
                std::cout << "Deleted " << key << " from the hash table." << std::endl;
                return;
            }
            i++;
            index = (hashFunction(key) + i * i) % capacity;
        }
        std::cout << key << " not found in the hash table." << std::endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        int i = 0; // Quadratic probing index

        while (table[index] != -1) {
            if (table[index] == key) {
                std::cout << key << " found in the hash table." << std::endl;
                return;
            }
            i++;
            index = (hashFunction(key) + i * i) % capacity;
        }
        std::cout << key << " not found in the hash table." << std::endl;
    }

    void display() {
        std::cout << "Hash Table Contents:" << std::endl;
        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1) {
                std::cout << "Index " << i << ": " << table[i] << std::endl;
            } else {
                std::cout << "Index " << i << ": Empty" << std::endl;
            }
        }
    }
};

int main() {
    int capacity;
    std::cout << "Enter the capacity of the hash table: ";
    std::cin >> capacity;

    HashTable hashTable(capacity);
    int choice, key;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Search\n";
        std::cout << "4. Display\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                hashTable.insert(key);
                break;
            case 2:
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                hashTable.deleteKey(key);
                break;
            case 3:
                std::cout << "Enter key to search: ";
                std::cin >> key;
                hashTable.search(key);
                break;
            case 4:
                hashTable.display();
                break;
            case 5:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}