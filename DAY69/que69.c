#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++; // increase indegree
    }

    queue<int> q;

    // Push nodes with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Check for cycle
    if (topo.size() != V) {
        cout << "Cycle detected, topological sort not possible\n";
    } else {
        for (int node : topo) {
            cout << node << " ";
        }
    }

    return 0;
}
