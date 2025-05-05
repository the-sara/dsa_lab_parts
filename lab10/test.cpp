#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<limits>

using namespace std;
template <typename T>
   bool isdirected = false;
    bool isweighted = false;
  
class my_graph {
public:
     static const int max = 4;
    static const int INF = 1000;
    int adj[max][max];// the adj matrix 
    
    T vertices[max];// to store the nodes names 

    my_graph(bool weight, bool dir, int matrix[max][max]);
    //void insert(string name,int );
    //void bfs(int s);
    //void dfs(int s);
    //void dijkstra(int start);
    //void floydwarshall();
};

template <typename T>
my_graph<T>::my_graph(bool weighted, bool dir, int matrix[max][max]) {
    isweighted = weight;
    isdirected = dir;
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            if (i == j) adj[i][j] = 0;
            else {
                if (weighted==true) {
                adj[i][j] = matrix[i][j];}
            else {
                if (i == j) adj[i][j] = 0;
                else adj[i][j] = 1;}
        }
    }
}}
int main() {
    int matrix[4][4] = {
        {0, 20, 2, 2},
        {2, 4, 5, 3},
        {3, 5, 6, 3},
        {3, 9, 5, 9}
    };

    my_graph<int> g(false, false, matrix);  // Using int type graph

    // Add vertices for testing traversal
    g.insert(0);
    g.insert(1);
    g.insert(2);
    g.insert(3);

    cout << "BFS starting from vertex 0:\n";
    g.bfs(0);

    cout << "\nDFS starting from vertex 0:\n";
    g.dfs(0);

    cout << "\nDijkstra starting from vertex 0:\n";
    g.dijkstra(0);

    return 0;
}
