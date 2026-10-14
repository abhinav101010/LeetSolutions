#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        queue<vector<int>> q;
        q.push(start);
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur[0], y = cur[1];
            if (x == destination[0] && y == destination[1]) {
                return true;
            }
            for (auto& d : dirs) {
                int nx = x, ny = y;
                // roll
                while (nx + d[0] >= 0 && nx + d[0] < m && ny + d[1] >= 0 && ny + d[1] < n && maze[nx + d[0]][ny + d[1]] == 0) {
                    nx += d[0];
                    ny += d[1];
                }
                if (!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }
};
