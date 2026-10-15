#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 0 uncolored, 1 color A, -1 color B
        for (int start = 0; start < n; start++) {
            if (color[start] != 0) continue;
            // BFS
            queue<int> q;
            q.push(start);
            color[start] = 1;
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int nb : graph[node]) {
                    if (color[nb] == 0) {
                        color[nb] = -color[node];
                        q.push(nb);
                    } else if (color[nb] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
