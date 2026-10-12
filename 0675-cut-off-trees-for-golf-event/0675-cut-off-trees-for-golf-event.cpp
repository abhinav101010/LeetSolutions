class Solution {
private:
    int m, n;
    vector<vector<int>> forest;
    
    int bfs(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty) return 0;
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<tuple<int,int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push(make_tuple(sx, sy, 0));
        visited[sx][sy] = true;
        while (!q.empty()) {
            auto [x, y, dist] = q.front(); q.pop();
            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && forest[nx][ny] != 0) {
                    if (nx == tx && ny == ty) return dist + 1;
                    visited[nx][ny] = true;
                    q.push(make_tuple(nx, ny, dist + 1));
                }
            }
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forestList) {
        m = forestList.size(); n = forestList[0].size();
        forest = forestList;
        vector<vector<int>> trees;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        int ans = 0, sx = 0, sy = 0;
        for (auto &t : trees) {
            int d = bfs(sx, sy, t[1], t[2]);
            if (d == -1) return -1;
            ans += d;
            sx = t[1]; sy = t[2];
        }
        return ans;
    }
};