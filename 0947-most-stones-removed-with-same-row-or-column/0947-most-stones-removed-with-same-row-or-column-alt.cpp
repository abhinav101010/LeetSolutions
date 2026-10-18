#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                deque<int> q;
                q.push_back(i);
                visited[i] = true;
                while (!q.empty()) {
                    int u = q.front(); q.pop_front();
                    for (int v : graph[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push_back(v);
                        }
                    }
                }
            }
        }
        return n - components;
    }
};
