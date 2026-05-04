#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii; // {distance, node}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pii>> adj(V);

    // Input edges (u, v, weight)
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // For undirected graph, also add:
        // adj[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        // Skip outdated entries
        if (d > dist[node]) continue;

        for (auto [neighbor, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}
