#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int maxArea = 0;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    int area = 0;
                    queue<pair<int,int>> q;
                    q.push({r, c});
                    visited[r][c] = true;
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        int cr = cur.first, cc = cur.second;
                        area++;
                        for (auto& dir : dirs) {
                            int nr = cr + dir.first;
                            int nc = cc + dir.second;
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1 && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
