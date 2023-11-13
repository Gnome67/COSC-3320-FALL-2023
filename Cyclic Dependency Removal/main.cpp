#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *adj; // Adjacency lists

    // DFS utility function to detect cycle in a graph
    bool isCyclicUtil(int v, bool visited[], bool *recStack, bool *inCycle) {
    if (!visited[v]) {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i] && isCyclicUtil(*i, visited, recStack, inCycle)) {
                inCycle[v] = true; // Mark as part of cycle
                return true;
            } else if (recStack[*i]) {
                inCycle[v] = true; // Mark as part of cycle
                return true;
            }
        }
    }

    // Remove the vertex from recursion stack
    recStack[v] = false;
    return false;
}

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
    }

    int countSatisfiableNodes() {
    // Mark all the vertices as not visited and not part of recursion stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    bool *inCycle = new bool[V]; // To mark nodes in a cycle
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
        inCycle[i] = false;
    }

    // Call the recursive helper function to detect cycle in different DFS trees
    for (int i = 0; i < V; i++)
        if (!visited[i])
            isCyclicUtil(i, visited, recStack, inCycle);

    // Count satisfiable nodes (not part of any cycle)
    int count = 0;
    for (int i = 0; i < V; i++)
        if (!inCycle[i])
            count++;

    return count;
    }
    
    // Debug function to print the graph
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "\n Adjacency list of vertex " << v << "\n head ";
            for (auto x : adj[v])
                cout << "-> " << x;
            printf("\n");
        }
    }
};

int main() {
    // Example Input
    int n = 0, m = 0, v = 0, w = 0;
    cin >> n;
    cin >> m;
    
    Graph g(n);
    for(int x = 0; x < m; x++)
    {
        cin >> v >> w;
        g.addEdge(v, w);
    }
    // g.printGraph();
    cout << g.countSatisfiableNodes();

    return 0;
}
