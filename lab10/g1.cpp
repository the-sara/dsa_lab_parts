#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    int adj[][];
public:
    Graph(int v) : V(v), adj(v, vector<int>(v, 0)) {}

    void addEdge(int u, int v) {
        adj[u][v] = adj[v][u] = 1;
    }

    void BFS(int start) {
        vector<bool> vis(V);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int v = 0; v < V; v++)
                if (adj[u][v] && !vis[v]) q.push(v), vis[v] = true;
        }
        cout << endl;
    }

    void DFS(int u, vector<bool>& vis) {
        vis[u] = true;
        cout << u << " ";
        for (int v = 0; v < V; v++)
            if (adj[u][v] && !vis[v]) DFS(v, vis);
    }

    void DFS(int start) {
        vector<bool> vis(V);
        DFS(start, vis);
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "DFS: "; g.DFS(0);
    cout << "BFS: "; g.BFS(0);
}
