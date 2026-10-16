#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        for (auto& r : relations) { adj[r[0]-1].push_back(r[1]-1); indeg[r[1]-1]++; }
        queue<int> q;
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.push(i);
        int sem = 0, taken = 0;
        while (!q.empty()) {
            sem++;
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                int u = q.front(); q.pop();
                taken++;
                for (int v : adj[u]) {
                    indeg[v]--;
                    if (indeg[v] == 0) q.push(v);
                }
            }
        }
        return taken == n ? sem : -1;
    }
};
