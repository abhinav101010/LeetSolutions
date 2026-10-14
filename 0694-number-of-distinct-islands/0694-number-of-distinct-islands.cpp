#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        set<string> shapes;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    vector<pair<int,int>> cells;
                    queue<pair<int,int>> q;
                    q.push({r, c});
                    visited[r][c] = true;
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        int cr = cur.first, cc = cur.second;
                        cells.push_back({cr, cc});
                        for (auto& dir : dirs) {
                            int nr = cr + dir.first;
                            int nc = cc + dir.second;
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1 && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                    // normalize
                    int minR = INT_MAX, minC = INT_MAX;
                    for (auto& cell : cells) {
                        minR = min(minR, cell.first);
                        minC = min(minC, cell.second);
                    }
                    vector<pair<int,int>> normalized;
                    for (auto& cell : cells) {
                        normalized.push_back({cell.first - minR, cell.second - minC});
                    }
                    // sort
                    sort(normalized.begin(), normalized.end());
                    // build string
                    string shape;
                    for (auto& p : normalized) {
                        shape += to_string(p.first) + "," + to_string(p.second) + ";";
                    }
                    shapes.insert(shape);
                }
            }
        }
        return shapes.size();
    }
};
