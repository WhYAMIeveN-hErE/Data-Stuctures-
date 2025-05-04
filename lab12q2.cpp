#include <iostream>
#include <vector>
#include <cstring> // for memset

using namespace std;

class Graph {
private:
    int vertices; // Number of vertices
    int** adjMatrix; // Adjacency matrix

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            memset(adjMatrix[i], 0, vertices * sizeof(int)); // Initialize to 0
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    // Insert edge (undirected)
    void insertEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            if (adjMatrix[u][v] == 0) { // Check if edge already exists
                adjMatrix[u][v] = 1;
                adjMatrix[v][u] = 1; // For undirected graph
                cout << "Edge inserted between " << u << " and " << v << endl;
            } else {
                cout << "Edge already exists between " << u << " and " << v << endl;
            }
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }

    // Delete edge (undirected)
    void deleteEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            if (adjMatrix[u][v] == 1) {
                adjMatrix[u][v] = 0;
                adjMatrix[v][u] = 0; // For undirected graph
                cout << "Edge deleted between " << u << " and " << v << endl;
            } else {
                cout << "No edge exists between " << u << " and " << v << endl;
            }
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }

    // Search edge
    void searchEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            if (adjMatrix[u][v] == 1) {
                cout << "Edge exists between " << u << " and " << v << endl;
            } else {
                cout << "Edge does not exist between " << u << " and " << v << endl;
            }
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }

    // Display graph adjacency matrix
    void displayGraph() {
        cout << "Graph adjacency matrix representation:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, choice, u, v;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph graph(vertices);

    do {
        cout << "\nMenu:\n"
             << "1. Insert Edge\n"
             << "2. Delete Edge\n"
             << "3. Search Edge\n"
             << "4. Display Graph\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter vertices to insert edge (u v): ";
                cin >> u >> v;
                graph.insertEdge(u, v);
                break;
            case 2:
                cout << "Enter vertices to delete edge (u v): ";
                cin >> u >> v;
                graph.deleteEdge(u, v);
                break;
            case 3:
                cout << "Enter vertices to search edge (u v): ";
                cin >> u >> v;
                graph.searchEdge(u, v);
                break;
            case 4:
                graph.displayGraph();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 5);

    return 0;
}