class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0], ny = y + dirs[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && rooms[nx][ny] == 2147483647) {
                    rooms[nx][ny] = rooms[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};