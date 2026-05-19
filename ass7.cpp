#include<iostream> 
using namespace std; 
 
#define ROW 10 
#define COL 10 
#define infi 9999 
 
class prims { 
    int graph[ROW][COL], n; 
 
public: 
 
     
    void createGraph() { 
        int i, j; 
 
        cout << "Enter Total Warehouses: "; 
        cin >> n; 
 
        cout << "\nEnter Adjacency Matrix:\n"; 
        for (i = 0; i < n; i++) { 
            for (j = i; j < n; j++) { 
                cout << "Enter distance between " << i << " and " << j << ": "; 
                cin >> graph[i][j]; 
                graph[j][i] = graph[i][j]; 
            } 
        } 
 
         
        for (i = 0; i < n; i++) { 
            for (j = 0; j < n; j++) { 
                if (graph[i][j] == 0) 
                    graph[i][j] = infi; 
            } 
        } 
 
         
        cout << "\nAdjacency Matrix:\n\n"; 
        for (i = 0; i < n; i++) { 
            for (j = 0; j < n; j++) { 
                if (graph[i][j] == infi) 
                    cout << "INF\t"; 
                else 
                    cout << graph[i][j] << "\t"; 
            } 
            cout << endl; 
        } 
    } 
 
     
    void primsAlgo() { 
        int selected[ROW], i, j, ne = 0; 
        int min, x = 0, y = 0; 
        int cost = 0; 
 
        for (i = 0; i < n; i++) 
            selected[i] = 0; 
 
        selected[0] = 1; 
 
        while (ne < n - 1) { 
            min = infi; 
 
            for (i = 0; i < n; i++) { 
                if (selected[i] == 1) { 
                    for (j = 0; j < n; j++) { 
                        if (selected[j] == 0 && graph[i][j] < min) { 
                            min = graph[i][j]; 
                            x = i; 
                            y = j; 
                        } 
                    } 
                } 
            } 
 
            cout << "\nEdge selected: " << x << " --> " << y; 
            cost += graph[x][y]; 
            selected[y] = 1; 
            ne++; 
        } 
 
        cout << "\n\nTotal cost is: " << cost << endl; 
    } 
}; 
 
int main() { 
    prims MST; 
 
cout << "\nPrim's Algorithm to connect several Warehouses\n"; 
MST.createGraph(); 
cout << "\nThe Edges are:\n"; 
MST.primsAlgo(); 
return 0; 
}