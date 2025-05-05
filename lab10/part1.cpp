//part 1 : graph class implementation :
#include<iostream>
#include<string>
#include <queue>

using namespace std;
template < typename T>

// the class
class my_graph {
public:
        bool isdirected=false;
        bool isweighted=false;
        static int max=4;
        // the adj matrix:
        int adj[max][max];
        T vertices[max];
        my_graph(bool weight,bool dir,T matric[max][max]);
        void insert(T elem);
        void dijkstra(int start);
        void dfs(int start);
        void bfs(int s);
};
// the constructor :
my_graph::my_graph(bool wheight,bool dir,T matric[max][max]){
        if(wheight==false){
            // not wheighted all wheights =1 
            for (int i=0;i<max;i++){
                for (int j=0;i<max;j++)  {
                    adj[i][j]=1;
                }
            }}
        else{
            for (int i=0;i<max;i++){
                for (int j=0;i<max;j++)  {
                    adj[i][j]=matric[i][j];
        }
        }}}

// inserting a new vertix :
void my_graph:: insert(T elem){
    int ins=max;
    max++;
    adj[ins][ins]=elem;
}
//bfs:using queue:
void my_graph::bfs(int s){
    bool visited[max] = { false };
    std::queue<int> q;

    visited[start] = true;
    q.push(start)

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout<< vertice[current];//output

    for (int i = 0; i < max; ++i) {
            if (adj[current][i] != INF && !visited[i] && current != i) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
//dfs using stack :
void my_graph:: dfs(int start) {
    bool visited[max] = { false };
    std::stack<int> s;

    visited[start] = true;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        std::cout << vertices[current] << " ";

        for (int i = 0; i < numVertices; ++i) {
            if (adj[current][i] != INF && !visited[i] && current != i) {
                visited[i] = true;
                s.push(i);
            }
        }
    }
}
void my_graph:: dijkstra(int start) {
    int dist[max];// distance array 
    bool visited[max] = { false };// the visited array 

    for (int i = 0; i < max; ++i)
        dist[i] = INF;

    dist[start] = 0;

    for (int i = 0; i < max - 1; ++i) {
        int u = -1, selected  = INF;

        for (int j = 0; j < max; ++j) {
            if (!visited[j] && dist[j] < selected ) {
                selected = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < max; ++v) {
            if (!visited[j] && adj[i][i] != INF && dist[i] + adj[i][j] < dist[j]) {
                dist[j] = dist[i] + adj[i][j];
            }
        }
    }

    for (int i = 0; i < max; ++i) {// output
        if (dist[i] == INF)
            std::cout << "INF";
        else
            std::cout << dist[i] ;
    }
}
int main() {
    int matrix[4][4] = {
        {0, 20, 2, 2},
        {2, 4, 5, 3},
        {3, 5, 6, 3},
        {3, 9, 5, 9}
    };

    my_graph g =my_graph (false, false, matrix);  // Using int type graph

    // Add vertices for testing traversal
    g.insert(0);
    g.insert(1);
    g.insert(2);
    g.insert(3);

    g.bfs(0);
    g.dfs(0);
    g.dijkstra(0);

    return 0;
}


