#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
#include <stack>
using namespace std;

void topologicalSortUtil(int node, vector<bool>& visited, stack<int>& Stack, const vector<list<pair<int, int>>>& adj) {
    visited[node] = true;
    for (auto i : adj[node]) {
        if (!visited[i.first])
            topologicalSortUtil(i.first, visited, Stack, adj);
    }
    Stack.push(node);
}

int longestPath(int start, int end, const vector<list<pair<int, int>>>& adj, int N) {
    stack<int> Stack;
    vector<bool> visited(N, false);
    for (int i = 0; i < N; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack, adj);

    vector<int> dist(N, INT_MIN);
    dist[start] = 0;

    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();

        if (dist[u] != INT_MIN) {
            for (auto i : adj[u])
                if (dist[i.first] < dist[u] + i.second)
                    dist[i.first] = dist[u] + i.second;
        }
    }

    return (dist[end] == INT_MIN) ? 0 : dist[end];
}

int main() {
    int N, M, start, end;
    cin >> N >> M;
    cin >> start >> end;
    
    vector<list<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back(make_pair(v, weight));
    }

    cout << longestPath(start, end, adj, N) << endl;

    return 0;
}
