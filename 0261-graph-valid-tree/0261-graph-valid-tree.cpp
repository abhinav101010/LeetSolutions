class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : graph[cur]) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
};