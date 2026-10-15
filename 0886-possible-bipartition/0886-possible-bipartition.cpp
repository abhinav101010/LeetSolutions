#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto& e : dislikes) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> color(n + 1, 0); // 0 uncolored, 1 and -1
        for (int start = 1; start <= n; start++) {
            if (color[start] != 0) continue;
            queue<int> q;
            q.push(start);
            color[start] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : graph[u]) {
                    if (color[v] == 0) {
                        color[v] = -color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
