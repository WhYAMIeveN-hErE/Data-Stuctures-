#include <iostream>
#include <list>
#include <vector>

class HashTable {
private:
    std::vector<std::list<int>> table; // Hash table using separate chaining
    int capacity;

    int hashFunction(int key) {
        return key % capacity; // Simple hash function
    }

public:
    HashTable(int cap) : capacity(cap) {
        table.resize(capacity); // Initialize the hash table with empty lists
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key); // Insert key into the list at the hashed index
        std::cout << "Inserted " << key << " into the hash table." << std::endl;
    }

    void deleteKey(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        auto it = std::find(chain.begin(), chain.end(), key);
        
        if (it != chain.end()) {
            chain.erase(it); // Remove the key from the list
            std::cout << "Deleted " << key << " from the hash table." << std::endl;
        } else {
            std::cout << key << " not found in the hash table." << std::endl;
        }
    }

    void search(int key) {
        int index = hashFunction(key);
        auto& chain = table[index];
        auto it = std::find(chain.begin(), chain.end(), key);
        
        if (it != chain.end()) {
            std::cout << key << " found in the hash table." << std::endl;
        } else {
            std::cout << key << " not found in the hash table." << std::endl;
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
        std::cout << "4. Exit\n";
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
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}