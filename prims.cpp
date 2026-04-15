#include <iostream>
using namespace std;

#define ROW 10
#define COL 10
#define infi 9999

class prims {
    int graph[ROW][COL], nodes;

public:
    void createGraph() {
        int i, j;

        cout << "Enter Total Warehouses: ";
        cin >> nodes;

        // Initialize graph with infinity
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                graph[i][j] = infi;
            }
        }

        cout << "\nEnter Adjacency Matrix:\n";
        for (i = 0; i < nodes; i++) {
            for (j = i; j < nodes; j++) {
                cout << "Enter distance between " << i << " and " << j << ": ";
                cin >> graph[i][j];
                graph[j][i] = graph[i][j];
            }
        }

        // Replace 0 with infinity (except diagonal)
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                if (i != j && graph[i][j] == 0) {
                    graph[i][j] = infi;
                }
            }
        }

        // Display matrix
        cout << "\nAdjacency Matrix:\n";
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                if (graph[i][j] == infi)
                    cout << "INF ";
                else
                    cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void primsAlgo() {
        int selected[ROW], i, j, ne = 0;
        int min, x = 0, y = 0;
        int cost = 0;

        for (i = 0; i < nodes; i++)
            selected[i] = 0;

        selected[0] = 1; // start from node 0

        while (ne < nodes - 1) {
            min = infi;

            for (i = 0; i < nodes; i++) {
                if (selected[i] == 1) {
                    for (j = 0; j < nodes; j++) {
                        if (selected[j] == 0 && graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }

            cout << x << " --> " << y << endl;
            cost += graph[x][y];
            selected[y] = 1;
            ne++;
        }

        cout << "Total cost is: " << cost << endl;
    }
};

int main() {
    prims MST;

    cout << "\nPrim's Algorithm to connect Warehouses\n";

    MST.createGraph();

    cout << "\nThe Edges are:\n";
    MST.primsAlgo();

    return 0;
}