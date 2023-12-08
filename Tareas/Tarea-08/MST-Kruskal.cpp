// C++ program for Kruskal's algorithm to find Minimum
// Spanning Tree of a given connected, undirected and
// weighted graph
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

// Structure to represent a graph
struct Graph {
  int V, E;
  vector<vector<int>> edges;

  // Constructor
  Graph(int V, int E) {
    this->V = V;
    this->E = E;
	// initialize the adjacency-matrix
    for (size_t i = 0; i < V; i++) {
      edges.push_back(vector<int>(V, numeric_limits<int>::max()));
    }
  }

  // Utility function to add an edge
  void addEdge(int u, int v, int w) {
    
    edges[u][v] = w;
    edges[v][u] = w;
  }

  // Function to find MST using Kruskal's
  // MST algorithm
  int kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets {
  int *parent, *rnk;
  int n;

  // Constructor.
  DisjointSets(int n) {
    // Allocate memory
    this->n = n;
    parent = new int[n + 1];
    rnk = new int[n + 1];

    // Initially, all vertices are in
    // different sets and have rank 0.
    for (int i = 0; i <= n; i++) {
      rnk[i] = 0;

      // every element is parent of itself
      parent[i] = i;
    }
  }

  // Find the parent of a node 'u'
  // Path Compression
  int find(int u) {
    /* Make the parent of the nodes in the path
    from u--> parent[u] point to parent[u] */
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }

  // Union by rank
  void merge(int x, int y) {
    x = find(x), y = find(y);

    /* Make tree with smaller height
    a subtree of the other tree */
    if (rnk[x] > rnk[y])
      parent[y] = x;
    else // If rnk[x] <= rnk[y]
      parent[x] = y;

    if (rnk[x] == rnk[y])
      rnk[y]++;
  }
};

/* Functions returns weight of the MST*/

int Graph::kruskalMST() {
  int mst_wt = 0; // Initialize result


  // Create disjoint sets
  DisjointSets ds(V);

  // Iterate through all sorted edges
  // vector< pair<int, iPair> >::iterator it;
  for (size_t edge_count = 0; edge_count < V - 1; edge_count++) {
    int min = numeric_limits<int>::max();
    int i = -1, j = -1;
    for (int u = 0; u < V; u++) {   // rows
      for (int v = 0; v < u; v++) { // cols

        if (!(edges[u][v] < min))
          continue;

        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v ) {
          min = edges[u][v];
          i = u;
          j = v;
        }
      }
    }
    if (i != -1 && j != -1) {
      mst_wt += min;
      cout << i << " - " << j << endl;
      ds.merge(ds.find(i), ds.find(j));
    }
  }

  return mst_wt;
}

// Driver program to test above functions
int main() {
  /* Let us create above shown weighted
  and undirected graph */
  int V = 11, E = 12;
  Graph g(V, E);

  // making above shown graph
  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 9, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);

  //   for (const auto &row : g.edges) {
  //     for (const auto &col : row) {
  //       cout << col << ' ';
  //     }
  //     cout << '\n';
  //   }

  cout << "Edges of MST are \n";
  int mst_wt = g.kruskalMST();

  cout << "\nWeight of MST is " << mst_wt << "\n";

  return 0;
}
