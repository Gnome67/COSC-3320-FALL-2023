#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    unsigned int weight;
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(const pair<int, unsigned int>& a, const pair<int, unsigned int>& b) {
        return a.second < b.second;
    }
};

vector<unsigned int> maxWeightPaths(int n, const vector<vector<Edge>>& graph) {
    vector<unsigned int> maxWeight(n, 0); // Stores the max weight that can reach each island
    priority_queue<pair<int, unsigned int>, vector<pair<int, unsigned int>>, Compare> pq;

    maxWeight[0] = UINT_MAX; // Start with the maximum possible weight for the starting node
    pq.push({0, maxWeight[0]});

    while (!pq.empty()) {
        int node = pq.top().first;
        unsigned int weight = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[node]) {
            // Take the minimum of the current weight and the edge weight
            unsigned int pathWeight = min(weight, edge.weight);
            // If this path can carry more weight, update the maxWeight and add to the queue
            if (pathWeight > maxWeight[edge.to]) {
                maxWeight[edge.to] = pathWeight;
                pq.push({edge.to, pathWeight});
            }
        }
    }

    return maxWeight;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; ++i) {
        int src, dst;
        unsigned int weight;
        cin >> src >> dst >> weight;
        graph[src].push_back({dst, weight});
        graph[dst].push_back({src, weight}); // The graph is undirected
    }

    vector<unsigned int> maxWeights = maxWeightPaths(n, graph);

    // Output the maximum weight for each island except the starting one
    for (int i = 1; i < n; ++i) {
        cout << maxWeights[i] << (i < n - 1 ? " " : "\n");
    }

    return 0;
}
