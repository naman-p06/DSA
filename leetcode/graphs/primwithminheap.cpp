#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    vector<pair<pair<int, int>, int>> ans;
    vector<list<pair<int, int>>> adj(n + 1);
    
    // Building the adjacency list
    for (int i = 0; i < g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // Prim's algorithm initialization
    vector<int> parent(n + 1, -1);
    vector<bool> inMST(n + 1, false);
    vector<int> key(n + 1, INT_MAX);
    key[1] = 0;
    
    // Min-heap priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        inMST[u] = true;
        
        // Relaxing edges
        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    // Collecting the result
    for (int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});
    }
    
    return ans;
}
