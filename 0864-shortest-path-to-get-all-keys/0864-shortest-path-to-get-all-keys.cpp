#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cctype>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sx = 0, sy = 0;
        int keyCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '@') { sx = i; sy = j; }
                if (islower(c)) keyCount++;
            }
        }
        if (keyCount == 0) return 0;
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<tuple<int,int,int,int>> q; // x, y, mask, dist
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(1 << keyCount, false)));
        q.push({sx, sy, 0, 0});
        visited[sx][sy][0] = true;
        while (!q.empty()) {
            auto [x, y, mask, dist] = q.front(); q.pop();
            if (mask == (1 << keyCount) - 1) return dist;
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                char c = grid[nx][ny];
                if (c == '#') continue;
                int nmask = mask;
                if (islower(c)) {
                    int bit = c - 'a';
                    nmask |= (1 << bit);
                } else if (isupper(c)) {
                    int bit = c - 'A';
                    if ((mask & (1 << bit)) == 0) continue;
                }
                if (!visited[nx][ny][nmask]) {
                    visited[nx][ny][nmask] = true;
                    q.push({nx, ny, nmask, dist + 1});
                }
            }
        }
        return -1;
    }
};
