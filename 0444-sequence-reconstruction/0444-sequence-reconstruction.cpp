#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indeg;
        for (const auto &seq : sequences) {
            for (int i = 0; i < (int)seq.size(); ++i) {
                if (indeg.find(seq[i]) == indeg.end()) indeg[seq[i]] = 0;
                if (i > 0) {
                    graph[seq[i - 1]].push_back(seq[i]);
                    ++indeg[seq[i]];
                    --indeg[seq[i - 1]];
                }
            }
        }
        queue<int> q;
        for (const auto &p : indeg) {
            if (p.second == 0) q.push(p.first);
        }
        if (q.size() != 1) return false;
        vector<int> order;
        while (!q.empty()) {
            if (q.size() > 1) return false;
            int cur = q.front(); q.pop();
            order.push_back(cur);
            for (int nxt : graph[cur]) {
                --indeg[nxt];
                if (indeg[nxt] == 0) q.push(nxt);
            }
        }
        if (order.size() != n) return false;
        for (int i = 0; i < n; ++i) {
            if (order[i] != nums[i]) return false;
        }
        return true;
    }
};
