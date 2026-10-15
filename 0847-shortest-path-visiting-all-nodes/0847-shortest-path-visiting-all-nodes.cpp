#include <vector>
#include <queue>
#include <cstring>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;
        int maxMask = 1 << n;
        vector<vector<bool>> visited(n, vector<bool>(maxMask, false));
        queue<tuple<int,int,int>> q; // node, mask, dist
        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            visited[i][mask] = true;
            q.push({i, mask, 0});
        }
        while (!q.empty()) {
            auto [node, mask, dist] = q.front(); q.pop();
            if (mask == maxMask - 1) {
                return dist;
            }
            for (int nei : graph[node]) {
                int nmask = mask | (1 << nei);
                if (!visited[nei][nmask]) {
                    visited[nei][nmask] = true;
                    q.push({nei, nmask, dist + 1});
                }
            }
        }
        return -1;
    }
};
