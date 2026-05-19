#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, adj[10][10], visited[10];
vector<int> adjList[10];
string place[10];

// DFS using Adjacency Matrix
void dfs(int v)
{
    visited[v] = 1;
    cout << place[v] << " ";

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

// BFS using Adjacency List
void bfs(int s)
{
    int vis[10] = {0};
    queue<int> q;

    vis[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        cout << place[v] << " ";

        for(int i = 0; i<adjList[v].size(); i++)
        {
            int u = adjList[v][i];

            if(vis[u] == 0)
            {
                vis[u] = 1;
                q.push(u);
            }
        }
    }
}

int main()
{
    int s, ch;

    cout << "Enter number of places: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Place " << i << ": ";
        cin >> place[i];
    }

    cout << "Enter adjacency matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> adj[i][j];

            if(adj[i][j] == 1)
                adjList[i].push_back(j);
        }
    }

    do
    {
        cout << "\n1.DFS\n2.BFS\n3.Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        if(ch == 1)
        {
            for(int i = 0; i < n; i++)
                visited[i] = 0;

            cout << "Enter start vertex: ";
            cin >> s;

            cout << "DFS Traversal: ";
            dfs(s);
            cout << endl;
        }

        else if(ch == 2)
        {
            cout << "Enter start vertex: ";
            cin >> s;

            cout << "BFS Traversal: ";
            bfs(s);
            cout << endl;
        }

    } while(ch != 3);

    return 0;
}