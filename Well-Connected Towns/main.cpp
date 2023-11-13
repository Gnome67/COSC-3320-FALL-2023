#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int src, const vector<vector<pair<int, int>>>& adj, int d) {
    int n = adj.size();
    vector<int> dist(n, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();
        if (current_dist > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (current_dist + w <= d && current_dist + w < dist[v]) {
                dist[v] = current_dist + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n, d, k, b, m;
    cin >> n >> d >> k >> b >> m;
    vector<int> bus_stations(b);
    for (int i = 0; i < b; i++) {
        cin >> bus_stations[i];
    }

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> reachable_count(n, 0);
    for (int station : bus_stations) {
        auto distances = dijkstra(station, adj, d);
        for (int i = 0; i < n; i++) {
            if (distances[i] <= d) {
                reachable_count[i]++;
            }
        }
    }

    int well_connected_towns = 0;
    for (int i = 0; i < n; i++) {
        if (reachable_count[i] >= k) {
            well_connected_towns++;
        }
    }
    cout << well_connected_towns << endl;

    return 0;
}
