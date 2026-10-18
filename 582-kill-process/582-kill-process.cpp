#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> result;
        // Build parent -> list of children
        unordered_map<int, vector<int> > tree;
        for (size_t i = 0; i < pid.size(); ++i) {
            tree[ppid[i]].push_back(pid[i]);
        }
        // BFS to kill all descendants (including kill itself)
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            result.push_back(cur);
            auto it = tree.find(cur);
            if (it != tree.end()) {
                for (int child : it->second) {
                    q.push(child);
                }
            }
        }
        return result;
    }
};
