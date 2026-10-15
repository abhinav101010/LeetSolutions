class Solution {
    public int uniquePathsIII(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[] start = new int[2];
        int zeroCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start[0] = i;
                    start[1] = j;
                } else if (grid[i][j] == 0) {
                    zeroCount++;
                }
            }
        }
        return dfs(grid, start[0], start[1], zeroCount);
    }
    private int dfs(int[][] grid, int x, int y, int remaining) {
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == -1) {
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
}
