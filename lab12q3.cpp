#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

class Graph {
private:
    int vertices;
    int** adjMatrix;

    // For Kruskal's Algorithm
    struct Edge {
        int src, dest, weight;
    };

    // Helper for Kruskal
    int findSet(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findSet(parent, parent[i]);
    }

    void unionSet(int parent[], int rank[], int x, int y) {
        int xroot = findSet(parent, x);
        int yroot = findSet(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[yroot] < rank[xroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    void quickSortEdges(Edge edges[], int low, int high) {
        if (low < high) {
            int pi = partition(edges, low, high);
            quickSortEdges(edges, low, pi - 1);
            quickSortEdges(edges, pi + 1, high);
        }
    }

    int partition(Edge edges[], int low, int high) {
        int pivot = edges[high].weight;
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (edges[j].weight < pivot) {
                i++;
                swap(edges[i], edges[j]);
            }
        }
        swap(edges[i + 1], edges[high]);
        return (i + 1);
    }

public:
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

    ~Graph() {
        for (int i = 0; i < vertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }

    void insertEdge(int u, int v, int w) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices && w > 0) {
            adjMatrix[u][v] = w;
            adjMatrix[v][u] = w;  // Undirected graph
            cout << "Edge inserted between " << u << " and " << v << " with weight " << w << endl;
        } else {
            cout << "Invalid input! Vertex out of range or weight invalid." << endl;
        }
    }

    void displayGraph() {
        cout << "Adjacency Matrix:" << endl << "    ";
        for (int i = 0; i < vertices; i++)
            cout << i << " ";
        cout << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Prim's algorithm for MST
    void primMST() {
        int* parent = new int[vertices];
        int* key = new int[vertices];
        bool* mstSet = new bool[vertices];

        for (int i = 0; i < vertices; i++) {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }

        key[0] = 0;     // Start from vertex 0
        parent[0] = -1; // First node is root of MST

        for (int count = 0; count < vertices - 1; count++) {
            int u = -1;
            int minKey = INT_MAX;
            // Pick the minimum key vertex from vertices not yet included in MST
            for (int v = 0; v < vertices; v++) {
                if (!mstSet[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            if (u == -1) {
                cout << "Graph not connected or no more reachable vertices." << endl;
                break;
            }
            mstSet[u] = true;

            // Update key and parent for adjacent vertices
            for (int v = 0; v < vertices; v++) {
                if (adjMatrix[u][v] && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        cout << "Prim's MST edges (u - v : weight):" << endl;
        int totalWeight = 0;
        for (int i = 1; i < vertices; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << endl;
                totalWeight += adjMatrix[i][parent[i]];
            }
        }
        cout << "Total weight of MST: " << totalWeight << endl;

        delete[] parent;
        delete[] key;
        delete[] mstSet;
    }

    // Kruskal's algorithm for MST
    void kruskalMST() {
        int maxEdges = vertices * (vertices - 1) / 2;
        Edge* edges = new Edge[maxEdges];
        int edgeCount = 0;

        // Extract all edges from the adjacency matrix (undirected & avoid duplicates)
        for (int i = 0; i < vertices; i++) {
            for (int j = i + 1; j < vertices; j++) {
                if (adjMatrix[i][j] != 0) {
                    edges[edgeCount++] = {i, j, adjMatrix[i][j]};
                }
            }
        }

        // Sort edges by weight
        quickSortEdges(edges, 0, edgeCount - 1);

        int* parent = new int[vertices];
        int* rank = new int[vertices];
        for (int i = 0; i < vertices; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int countEdges = 0;
        int totalWeight = 0;
        cout << "Kruskal's MST edges (u - v : weight):" << endl;
        for (int i = 0; i < edgeCount && countEdges < vertices - 1; i++) {
            int uRoot = findSet(parent, edges[i].src);
            int vRoot = findSet(parent, edges[i].dest);

            if (uRoot != vRoot) {
                cout << edges[i].src << " - " << edges[i].dest << " : " << edges[i].weight << endl;
                totalWeight += edges[i].weight;
                unionSet(parent, rank, uRoot, vRoot);
                countEdges++;
            }
        }

        if (countEdges != vertices - 1) {
            cout << "Graph is not connected, MST could not be formed completely." << endl;
        } else {
            cout << "Total weight of MST: " << totalWeight << endl;
        }

        delete[] edges;
        delete[] parent;
        delete[] rank;
    }

    // Dijkstra's algorithm for shortest path from source
    void dijkstra(int src) {
        if (src < 0 || src >= vertices) {
            cout << "Invalid source vertex!" << endl;
            return;
        }

        int* dist = new int[vertices];
        bool* sptSet = new bool[vertices]; // shortest path tree set

        for (int i = 0; i < vertices; i++) {
            dist[i] = INT_MAX;
            sptSet[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int u = -1;
            int minDist = INT_MAX;

            // Pick vertex with minimum distance from set of vertices not yet processed
            for (int v = 0; v < vertices; v++) {
                if (!sptSet[v] && dist[v] < minDist) {
                    minDist = dist[v];
                    u = v;
                }
            }

            if (u == -1)
                break;

            sptSet[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (adjMatrix[u][v] && !sptSet[v] && dist[u] != INT_MAX &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        cout << "Vertex\tDistance from Source " << src << endl;
        for (int i = 0; i < vertices; i++) {
            if (dist[i] == INT_MAX)
                cout << i << "\t" << "INF" << endl;
            else
                cout << i << "\t" << dist[i] << endl;
        }

        delete[] dist;
        delete[] sptSet;
    }
};

int main() {
    int vertices;
    cout << "Enter number of vertices in the graph: ";
    cin >> vertices;
    if (vertices <= 0) {
        cout << "Number of vertices must be positive." << endl;
        return 1;
    }

    Graph graph(vertices);

    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Insert Edge\n"
             << "2. Display Graph\n"
             << "3. Run Prim's MST Algorithm\n"
             << "4. Run Kruskal's MST Algorithm\n"
             << "5. Run Dijkstra's Shortest Path Algorithm\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int u, v, w;
                cout << "Enter edge vertices (u v) and weight: ";
                cin >> u >> v >> w;
                graph.insertEdge(u, v, w);
                break;
            }
            case 2:
                graph.displayGraph();
                break;
            case 3:
                graph.primMST();
                break;
            case 4:
                graph.kruskalMST();
                break;
            case 5: {
                int src;
                cout << "Enter source vertex for Dijkstra's algorithm: ";
                cin >> src;
                graph.dijkstra(src);
                break;
            }
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}