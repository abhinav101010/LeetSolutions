#include <string>
#include <queue>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        queue<string> q;
        unordered_set<string> visited;
        q.push(s1);
        visited.insert(s1);
        int steps = 0;
        int n = s1.size();
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front(); q.pop();
                int idx = 0;
                while (idx < n && cur[idx] == s2[idx]) idx++;
                string nxt = cur;
                for (int j = idx + 1; j < n; j++) {
                    if (nxt[j] == s2[idx] && nxt[j] != s2[j]) {
                        swap(nxt[idx], nxt[j]);
                        if (nxt == s2) return steps + 1;
                        if (visited.find(nxt) == visited.end()) {
                            visited.insert(nxt);
                            q.push(nxt);
                        }
                        swap(nxt[idx], nxt[j]); // backtrack
                    }
                }
            }
            steps++;
        }
        return steps;
    }
};
