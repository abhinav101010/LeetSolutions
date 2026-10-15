#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rgraph(n);
        vector<int> outdegree(n, 0);
        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();
            for (int v : graph[u]) {
                rgraph[v].push_back(u);
            }
        }
        queue<int> q;
        vector<bool> safe(n, false);
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            safe[u] = true;
            for (int v : rgraph[u]) {
                outdegree[v]--;
                if (outdegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};
