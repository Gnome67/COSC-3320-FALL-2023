#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(int u, vector<int>& index, vector<int>& lowLink, stack<int>& s, vector<bool>& onStack, int& currentIndex, int& sccCount, const vector<vector<int>>& adj) {
    index[u] = currentIndex;
    lowLink[u] = currentIndex;
    currentIndex++;
    s.push(u);
    onStack[u] = true;

    // Visit all successors of u
    for (int v : adj[u]) {
        if (index[v] == -1) {
            dfs(v, index, lowLink, s, onStack, currentIndex, sccCount, adj);
            lowLink[u] = min(lowLink[u], lowLink[v]);
        } else if (onStack[v]) {
            lowLink[u] = min(lowLink[u], index[v]);
        }
    }

    // Check if u is a root node of an SCC
    if (lowLink[u] == index[u]) {
        while (s.top() != u) {
            onStack[s.top()] = false;
            s.pop();
        }
        onStack[u] = false;
        s.pop();
        sccCount++;
    }
}

int countSCCs(int n, const vector<vector<int>>& adj) {
    vector<int> index(n, -1), lowLink(n, 0);
    vector<bool> onStack(n, false);
    stack<int> s;
    int currentIndex = 0, sccCount = 0;

    for (int i = 0; i < n; ++i) {
        if (index[i] == -1) {
            dfs(i, index, lowLink, s, onStack, currentIndex, sccCount, adj);
        }
    }

    return sccCount;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; ++i) {
        int node, edges;
        cin >> node >> edges;
        node--; // Adjusting for zero-based index
        for (int j = 0; j < edges; ++j) {
            int successor;
            cin >> successor;
            adj[node].push_back(successor - 1); // Adjusting for zero-based index
        }
    }

    cout << countSCCs(n, adj) << endl;

    return 0;
}
