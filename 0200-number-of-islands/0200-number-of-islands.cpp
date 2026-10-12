class Solution {
public:
    int numIslands(vector<string>& grid) {
        if (grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++ans;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return ans;
    }

private:
    void dfs(vector<string>& grid, int i, int j, int rows, int cols) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j, rows, cols);
        dfs(grid, i - 1, j, rows, cols);
        dfs(grid, i, j + 1, rows, cols);
        dfs(grid, i, j - 1, rows, cols);
    }
};