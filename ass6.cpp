#include <iostream>
#include <climits>
using namespace std;

class UtilityGrid {

public:

    int n;
    int adj[20][20];
    string station[20];

    void createGraph() {

        cout<<"Enter number of power stations: ";
        cin>>n;

        cout<<"Enter station names:\n";

        for(int i=0;i<n;i++)
            cin>>station[i];

        cout<<"Enter adjacency matrix:\n";

        for(int i=0;i<n;i++) {

            for(int j=0;j<n;j++) {

                cin>>adj[i][j];

                if(adj[i][j]==0 && i!=j)
                    adj[i][j]=INT_MAX;
            }
        }
    }

    void dijkstra(int start, int dist[]) {

        bool visited[20];

        for(int i=0;i<n;i++) {

            dist[i]=INT_MAX;
            visited[i]=false;
        }

        dist[start]=0;

        for(int count=0; count<n-1; count++) {

            int min=INT_MAX, u=-1;

            for(int i=0;i<n;i++) {

                if(!visited[i] && dist[i]<=min) {

                    min=dist[i];
                    u=i;
                }
            }

            if(u==-1)
                break;

            visited[u]=true;

            for(int v=0; v<n; v++) {

                if(!visited[v] &&
                   adj[u][v]!=INT_MAX &&
                   dist[u]!=INT_MAX &&
                   dist[u]+adj[u][v] < dist[v]) {

                    dist[v]=dist[u]+adj[u][v];
                }
            }
        }
    }

    void reachableStations(int dist[], int limit) {

        cout<<"\nReachable Stations:\n";

        for(int i=0;i<n;i++) {

            if(dist[i] <= limit)
                cout<<station[i]<<" = "<<dist[i]<<endl;
        }
    }
};

int main() {

    UtilityGrid g;

    int start, limit;
    int dist[20];

    g.createGraph();

    cout<<"Enter source station index: ";
    cin>>start;

    g.dijkstra(start, dist);

    cout<<"\nShortest Distance:\n";

    for(int i=0;i<g.n;i++) {

        if(dist[i]==INT_MAX)
            cout<<g.station[i]<<" = No Path\n";

        else
            cout<<g.station[i]<<" = "<<dist[i]<<endl;
    }

    cout<<"\nEnter time limit: ";
    cin>>limit;

    g.reachableStations(dist, limit);

    return 0;
}