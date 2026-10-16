#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int m = grid.size(), n = grid[0].size();
        int orig = grid[r0][c0];
        if (orig == color) return grid;
        vector<vector<bool>> comp(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({r0, c0});
        comp[r0][c0] = true;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == orig && !comp[nr][nc]) {
                    comp[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        vector<pair<int,int>> border;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (!comp[r][c]) continue;
                bool isBorder = (r == 0 || r == m-1 || c == 0 || c == n-1);
                if (!isBorder) {
                    for (auto& d : dirs) {
                        if (grid[r+d[0]][c+d[1]] != orig) { isBorder = true; break; }
                    }
                }
                if (isBorder) border.push_back({r, c});
            }
        }
        for (auto& b : border) grid[b.first][b.second] = color;
        return grid;
    }
};
