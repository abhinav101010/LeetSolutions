class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> reach(m, vector<int>(n, 0));
        int buildings = 0;
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    buildings++;
                    queue<vector<int>> q;
                    q.push({i, j, 0});
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        int x = cur[0], y = cur[1], d = cur[2];
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dirs[k][0], ny = y + dirs[k][1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0 && reach[nx][ny] == buildings - 1) {
                                dist[nx][ny] += d + 1;
                                reach[nx][ny] = buildings;
                                q.push({nx, ny, d + 1});
                            }
                        }
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && reach[i][j] == buildings) {
                    res = min(res, dist[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};