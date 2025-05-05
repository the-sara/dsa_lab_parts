#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
class my_graph {
public:
    bool isdirected = false;
    bool isweighted = false;
    int max = 20;
    T adj[20][20];

    my_graph(bool weight, bool dir, T matric[20][20]);
    void insert(T elem);
    void bfs(int s);
    void dfs(int start);
    void dijkstra(int start);

    T vertices[20];
    int numVertices = 0;
    static const int INF = 1000;
};

// constructor
template <typename T>
my_graph<T>::my_graph(bool wheight, bool dir, T matric[20][20]) {
    if (wheight == false) {
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                adj[i][j] = 1;
            }
        }
    } else {
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < max; j++) {
                adj[i][j] = matric[i][j];
            }
        }
    }
}

// insert vertex
template <typename T>
void my_graph<T>::insert(T elem) {
    if (numVertices < max) {
        vertices[numVertices] = elem;
        numVertices++;
    }
}

// BFS
template <typename T>
void my_graph<T>::bfs(int start) {
    bool visited[20] = { false };
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << vertices[current] << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (adj[current][i] != INF && !visited[i] && current != i) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// DFS
template <typename T>
void my_graph<T>::dfs(int start) {
    bool visited[20] = { false };
    stack<int> s;

    visited[start] = true;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        cout << vertices[current] << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (adj[current][i] != INF && !visited[i] && current != i) {
                visited[i] = true;
                s.push(i);
            }
        }
    }
}

// Dijkstra
template <typename T>
void my_graph<T>::dijkstra(int start) {
    int dist[20];
    bool visited[20] = { false };

    for (int i = 0; i < numVertices; ++i)
        dist[i] = INF;

    dist[start] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        int u = -1, minDist = INF;

        for (int j = 0; j < numVertices; ++j) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && adj[u][v] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 0; i < numVertices; ++i) {
        cout << "From " << vertices[start] << " to " << vertices[i] << ": ";
        if (dist[i] == INF)
            cout << "inf" << endl;
        else
            cout << dist[i] << endl;
    }
}
