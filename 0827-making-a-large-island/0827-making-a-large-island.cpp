#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(vector<vector<int>>& grid, int r, int c, int id, int n) {
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) return 0;
        grid[r][c] = id;
        int sum = 1;
        for (auto [dr,dc] : dirs) {
            sum += dfs(grid, r+dr, c+dc, id, n);
        }
        return sum;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> size(n*n+1,0);
        int id = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int s = dfs(grid, i, j, id, n);
                    size[id] = s;
                    ++id;
                }
            }
        }
        int ans = 0;
        for (int v : size) ans = max(ans, v);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> seen;
                    int total = 1;
                    for (auto [dr,dc] : dirs) {
                        int ni = i+dr, nj = j+dc;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1) {
                            int root = grid[ni][nj];
                            if (!seen.count(root)) {
                                seen.insert(root);
                                total += size[root];
                            }
                        }
                    }
                    ans = max(ans, total);
                }
            }
        }
        return ans;
    }
};
