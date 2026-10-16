class Solution {
    public int numEnclaves(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 || i == m-1 || j == 0 || j == n-1) && grid[i][j] == 1) {
                    dfs(grid, i, j, m, n);
                }
            }
        }
        int ans = 0;
        for (int[] row : grid) {
            for (int cell : row) if (cell == 1) ans++;
        }
        return ans;
    }
    private void dfs(int[][] grid, int x, int y, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) return;
        grid[x][y] = 0;
        dfs(grid,x+1,y,m,n); dfs(grid,x-1,y,m,n);
        dfs(grid,x,y+1,m,n); dfs(grid,x,y-1,m,n);
    }
}
