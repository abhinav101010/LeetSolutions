#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // priority_queue that sorts by smallest time
        using Cell = tuple<int,int,int>; // time, r, c
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        while (!pq.empty()) {
            auto [time, r, c] = pq.top(); pq.pop();
            if (r == n-1 && c == n-1) {
                return time;
            }
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    int nt = max(time, grid[nr][nc]);
                    pq.push({nt, nr, nc});
                }
            }
        }
        return -1;
    }
};
