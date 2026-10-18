#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> tree;
        int n = pid.size();
        for (int i = 0; i < n; ++i) {
            tree[ppid[i]].push_back(pid[i]);
        }
        vector<int> res;
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            res.push_back(cur);
            for (int child : tree[cur]) {
                q.push(child);
            }
        }
        return res;
    }
};
