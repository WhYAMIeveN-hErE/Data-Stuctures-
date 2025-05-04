#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;

public:
    // Constructor to initialize the graph
    Graph(int v) {
        vertices = v;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Destructor to free memory
    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    // Insert edge between u and v
    void insertEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1; // for undirected graph
            cout << "Edge inserted between " << u << " and " << v << endl;
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }

    // Delete edge between u and v
    void deleteEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            if (adjMatrix[u][v] == 1) {
                adjMatrix[u][v] = 0;
                adjMatrix[v][u] = 0; // for undirected graph
                cout << "Edge deleted between " << u << " and " << v << endl;
            } else {
                cout << "No edge exists between " << u << " and " << v << endl;
            }
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }

    // Search for edge between u and v
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

    // Display adjacency matrix
    void displayGraph() {
        cout << "Adjacency Matrix:" << endl;
        cout << "   ";
        for (int i = 0; i < vertices; i++) {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, choice, u, v;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    Graph graph(vertices);

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the vertices to insert edge (u v): ";
                cin >> u >> v;
                graph.insertEdge(u, v);
                break;

            case 2:
                cout << "Enter the vertices to delete edge (u v): ";
                cin >> u >> v;
                graph.deleteEdge(u, v);
                break;

            case 3:
                cout << "Enter the vertices to search edge (u v): ";
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
