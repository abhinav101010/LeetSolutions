#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int sx = start[0], sy = start[1];
        dist[sx][sy] = 0;
        pq.push({0, sx, sy});
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int d = cur[0], x = cur[1], y = cur[2];
            if (d > dist[x][y]) continue;
            if (x == destination[0] && y == destination[1]) {
                return d;
            }
            for (auto& dir : dirs) {
                int nx = x, ny = y;
                int steps = 0;
                while (nx + dir[0] >= 0 && nx + dir[0] < m && ny + dir[1] >= 0 && ny + dir[1] < n && maze[nx + dir[0]][ny + dir[1]] == 0) {
                    nx += dir[0];
                    ny += dir[1];
                    steps++;
                }
                int nd = d + steps;
                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq.push({nd, nx, ny});
                }
            }
        }
        return -1;
    }
};
