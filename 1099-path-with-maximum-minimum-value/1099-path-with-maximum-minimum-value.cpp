#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        priority_queue<vector<int>> pq;
        pq.push({A[0][0], 0, 0});
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int score = cur[0], x = cur[1], y = cur[2];
            if (x == m-1 && y == n-1) return score;
            if (seen[x][y]) continue;
            seen[x][y] = true;
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx][ny]) {
                    pq.push({min(score, A[nx][ny]), nx, ny});
                }
            }
        }
        return -1;
    }
};
