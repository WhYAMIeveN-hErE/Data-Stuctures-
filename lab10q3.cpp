#include <iostream>
#include <vector>
#include <stdexcept>

class MaxHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int deleteMax() {
        if (heap.empty()) {
            throw std::runtime_error("Heap is empty");
        }
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return maxValue;
    }

    void display() const {
        if (heap.empty()) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }
        std::cout << "Heap elements: ";
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    bool search(int value) const {
        for (int v : heap) {
            if (v == value) {
                return true;
            }
        }
        return false;
    }

    void heapSort() {
        std::vector<int> sorted;
        while (!heap.empty()) {
            sorted.push_back(deleteMax());
        }
        std::cout << "Sorted elements: ";
        for (int value : sorted) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

void displayMenu() {
    std::cout << "Priority Queue Menu:" << std::endl;
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Delete" << std::endl;
    std::cout << "3. Display" << std::endl;
    std::cout << "4. Search" << std::endl;
    std::cout << "5. Sort (Heap Sort)" << std::endl;
    std::cout << "6. Exit" << std::endl;
}

int main() {
    MaxHeap pq;
    int choice, value;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Insert
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                pq.insert(value);
                break;
            case 2: // Delete
                try {
                    std::cout << "Deleted max value: " << pq.deleteMax() << std::endl;
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3: // Display
                pq.display();
                break;
            case 4: // Search
                std::cout << "Enter value to search: ";
                std::cin >> value;
                if (pq.search(value)) {
                    std::cout << value << " is found in the heap." << std::endl;
                } else {
                    std::cout << value << " is not found in the heap." << std::endl;
                }
                break;
            case 5: // Sort (Heap Sort)
                pq.heapSort();
                break;
            case 6: // Exit
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
``