#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            pos[org[i]] = i;
        }
        vector<vector<int>> adj(n + 1);
        vector<int> indeg(n + 1, 0);
        vector<bool> seen(n + 1, false);
        for (auto& seq : seqs) {
            for (int v : seq) {
                if (v < 1 || v > n) return false;
                seen[v] = true;
            }
            for (int i = 0; i < (int)seq.size() - 1; i++) {
                int u = seq[i], v = seq[i+1];
                adj[u].push_back(v);
                indeg[v]++;
            }
        }
        // check all numbers in org seen
        for (int v : org) {
            if (!seen[v]) return false;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int idx = 0;
        while (!q.empty()) {
            if (q.size() != 1) {
                return false;
            }
            int u = q.front(); q.pop();
            if (org[idx] != u) {
                return false;
            }
            idx++;
            for (int v : adj[u]) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
        return idx == n;
    }
};
