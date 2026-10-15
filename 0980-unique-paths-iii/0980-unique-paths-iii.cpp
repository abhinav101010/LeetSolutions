#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        pair<int,int> start;
        int zeroCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start = {i, j};
                } else if (grid[i][j] == 0) {
                    zeroCount++;
                }
            }
        }
        return dfs(grid, start.first, start.second, zeroCount);
    }
private:
    int dfs(vector<vector<int>>& grid, int x, int y, int remaining) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) {
            return 0;
        }
        if (grid[x][y] == 2) {
            return remaining == 0 ? 1 : 0;
        }
        int tmp = grid[x][y];
        grid[x][y] = -1;
        int paths = 0;
        paths += dfs(grid, x+1, y, remaining-1);
        paths += dfs(grid, x-1, y, remaining-1);
        paths += dfs(grid, x, y+1, remaining-1);
        paths += dfs(grid, x, y-1, remaining-1);
        grid[x][y] = tmp;
        return paths;
    }
};
