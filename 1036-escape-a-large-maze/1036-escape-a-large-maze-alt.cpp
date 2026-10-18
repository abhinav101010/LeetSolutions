#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        if (blocked.empty()) return true;
        unordered_set<long long> blockedSet;
        for (auto& b : blocked) blockedSet.insert((long long)b[0] * 1000000 + b[1]);
        int limit = blocked.size() * (blocked.size() - 1) / 2;
        return bfs(blockedSet, source, target, limit) && bfs(blockedSet, target, source, limit);
    }
private:
    bool bfs(unordered_set<long long>& blockedSet, vector<int>& start, vector<int>& end, int limit) {
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        unordered_set<long long> seen;
        seen.insert((long long)start[0] * 1000000 + start[1]);
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty() && (int)seen.size() <= limit) {
            auto [x, y] = q.front(); q.pop();
            if (x == end[0] && y == end[1]) return true;
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                long long key = (long long)nx * 1000000 + ny;
                if (nx >= 0 && nx < 1000000 && ny >= 0 && ny < 1000000 && !blockedSet.count(key) && !seen.count(key)) {
                    seen.insert(key);
                    q.push({nx, ny});
                }
            }
        }
        return (int)seen.size() > limit;
    }
};
