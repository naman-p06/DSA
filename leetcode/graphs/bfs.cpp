#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void bfs(unordered_map<int, bool> &visited, unordered_map<int, vector<int>> &lis, int s, vector<int> &ans) {
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        ans.push_back(a);

        for(int j = 0; j < lis[a].size(); j++) {
            if (!visited[lis[a][j]]) {
                q.push(lis[a][j]);
                visited[lis[a][j]] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {
    unordered_map<int, vector<int>> lis;
    for (int i = 0; i < adj.size(); i++) {
        int u = adj[i][0];
        int v = adj[i][1];
        lis[u].push_back(v);
        // Ensure to add all nodes in case of missing ones
        if (lis.find(v) == lis.end()) {
            lis[v] = vector<int>();
        }
    }

    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && lis.find(i) != lis.end()) {
            bfs(visited, lis, i, ans);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int m;
    cin>>m;
    vector<vector<int>> adj;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj.push_back({u, v});
    }

    vector<int> result = bfsTraversal(n, adj);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
