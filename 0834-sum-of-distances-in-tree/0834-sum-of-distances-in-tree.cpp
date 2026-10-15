#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> count(n, 1);
        vector<int> ans(n, 0);
        function<void(int,int)> dfs = [&](int u, int parent) {
            for (int v : graph[u]) {
                if (v == parent) continue;
                dfs(v, u);
                count[u] += count[v];
                ans[u] += ans[v] + count[v];
            }
        };
        function<void(int,int)> dfs2 = [&](int u, int parent) {
            for (int v : graph[u]) {
                if (v == parent) continue;
                ans[v] = ans[u] - count[v] + (n - count[v]);
                dfs2(v, u);
            }
        };
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
