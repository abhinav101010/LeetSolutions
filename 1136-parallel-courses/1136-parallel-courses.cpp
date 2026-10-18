#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> g(n + 1);
        vector<int> indeg(n + 1, 0);
        for (auto& r : relations) {
            g[r[0]].push_back(r[1]);
            indeg[r[1]]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) q.push(i);
        }
        int ans = 0, taken = 0;
        while (!q.empty()) {
            ans++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front(); q.pop();
                taken++;
                for (int v : g[u]) {
                    if (--indeg[v] == 0) q.push(v);
                }
            }
        }
        return taken == n ? ans : -1;
    }
};