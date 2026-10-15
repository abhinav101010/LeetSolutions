#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for (auto& e : richer) {
            int u = e[0], v = e[1];
            adj[v].push_back(u); // u richer than v
        }
        vector<int> ans(n, -1);
        function<int(int)> dfs = [&](int v) {
            if (ans[v] != -1) return ans[v];
            int bestPerson = v;
            int bestQuiet = quiet[v];
            for (int u : adj[v]) {
                int cand = dfs(u);
                if (quiet[cand] < bestQuiet) {
                    bestQuiet = quiet[cand];
                    bestPerson = cand;
                }
            }
            ans[v] = bestPerson;
            return ans[v];
        };
        for (int i = 0; i < n; i++) {
            dfs(i);
        }
        return ans;
    }
};
