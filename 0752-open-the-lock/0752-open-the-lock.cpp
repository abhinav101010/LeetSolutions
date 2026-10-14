#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front(); q.pop();
                if (cur == target) return steps;
                for (string nxt : neighbors(cur)) {
                    if (!dead.count(nxt) && !visited.count(nxt)) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    
private:
    vector<string> neighbors(string s) {
        vector<string> res;
        string t = s;
        for (int i = 0; i < 4; i++) {
            char c = t[i];
            // turn up
            t[i] = (c == '9') ? '0' : c + 1;
            res.push_back(t);
            // turn down
            t[i] = (c == '0') ? '9' : c - 1;
            res.push_back(t);
            // restore
            t[i] = c;
        }
        return res;
    }
};
