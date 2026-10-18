#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for (int i = 0; i < n; ++i) {
            sort(g[i].begin(), g[i].end(), [&](int x, int y) {
                return scores[x] > scores[y];
            });
            if (g[i].size() > 3) {
                g[i].resize(3);
            }
        }
        int ans = -1;
        for (const auto& e : edges) {
            int a = e[0], b = e[1];
            for (int c : g[a]) {
                for (int d : g[b]) {
                    if (c != b && c != d && a != d && c != a && d != b) {
                        int t = scores[a] + scores[b] + scores[c] + scores[d];
                        ans = max(ans, t);
                    }
                }
            }
        }
        return ans;
    }
};
