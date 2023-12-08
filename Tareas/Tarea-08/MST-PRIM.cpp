// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Number of vertices in the graph
// #define V 5

// Structure to represent a graph
struct Graph {
  int V, E;
  // list of adjacency (v, w)
  vector<vector<pair<int, int>>> edges;
  vector<int> parent;

  // Constructor
  Graph(int V, int E) {
    this->V = V;
    this->E = E;
    // initialize the adjacency-matrix
    for (size_t i = 0; i < V; i++) {
      edges.push_back(vector<pair<int, int>>());
    }
  }

  // Utility function to add an edge
  void addEdge(int u, int v, int w) {
    edges[u].push_back(make_pair(v, w));
    edges[v].push_back(make_pair(u, w));
  }

  // Function to find MST using Kruskal's
  // MST algorithm
};

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(vector<int> &key, vector<bool> &mstSet) {
  // Initialize min value
  int min = INT_MAX, min_index;
  int V = key.size();
  for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
      min = key[v], min_index = v;

  return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void printMST(vector<int> &parent, Graph &G) {
  cout << "Edge \tWeight\n";
  for (int i = 1; i < G.V; i++) {
    auto edge =
        find_if(G.edges[i].begin(), G.edges[i].end(),
                [v = parent[i]](pair<int, int> p) { return p.first == v; });
    // cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";

    cout << parent[i] << " - " << i << " \t" << (*edge).second << " \n";
  }
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(Graph &G) {
  // Array to store constructed MST
  int V = G.V;
  vector<int> parent(V);

  // Key values used to pick minimum weight edge in cut
  vector<int> key(V);

  // To represent set of vertices included in MST
  vector<bool> mstSet(V);

  // Initialize all keys as INFINITE
  for (int i = 0; i < V; i++)
    key[i] = INT_MAX, mstSet[i] = false;

  // Always include first 1st vertex in MST.
  // Make key 0 so that this vertex is picked as first
  // vertex.
  key[0] = 0;

  // First node is always root of MST
  parent[0] = -1;

  // The MST will have V vertices
  for (int count = 0; count < V - 1; count++) {

    // Pick the minimum key vertex from the
    // set of vertices not yet included in MST
    int u = minKey(key, mstSet);

    // Add the picked vertex to the MST Set
    mstSet[u] = true;

    // Update key value and parent index of
    // the adjacent vertices of the picked vertex.
    // Consider only those vertices which are not
    // yet included in MST
    for (const auto &edge : G.edges[u]) {

      // graph[u][v] is non zero only for adjacent
      // vertices of m mstSet[v] is false for vertices
      // not yet included in MST Update the key only
      // if graph[u][v] is smaller than key[v]
      int v = edge.first;
      int w = edge.second;
      if (mstSet[v] == false && w < key[v])
        parent[v] = u, key[v] = w;
    }

    // Print the constructed MST
    
  }
  printMST(parent, G);
}

// Driver's code
int main() {

  //   int graph[V][V] = {{0, 2, 0, 6, 0},
  //                      {2, 0, 3, 8, 5},
  //                      {0, 3, 0, 0, 7},
  //                      {6, 8, 0, 0, 9},
  //                      {0, 5, 7, 9, 0}};

  Graph g(5, 0);

  g.addEdge(1, 0, 2);
  g.addEdge(2, 1, 3);
  g.addEdge(3, 0, 6);
  g.addEdge(3, 1, 8);
  g.addEdge(4, 1, 5);
  g.addEdge(4, 2, 7);
  g.addEdge(4, 3, 9);
  // Print the solution
  primMST(g);

  return 0;
}

// la matriz de adjacencia la representamos como un vector de vectores

// This code is contributed by rathbhupendra
