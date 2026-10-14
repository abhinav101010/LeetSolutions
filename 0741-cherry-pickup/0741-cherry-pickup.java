import java.util.*;

class Solution {
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int[][][] memo = new int[n][n][n];
        for (int[][] layer : memo) {
            for (int[] row : layer) {
                Arrays.fill(row, Integer.MIN_VALUE);
            }
        }
        int ans = dfs(grid, 0, 0, 0, memo, n);
        return Math.max(ans, 0);
    }
    
    private int dfs(int[][] grid, int r1, int c1, int r2, int[][][] memo, int n) {
        int c2 = r1 + c1 - r2;
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n) {
            return Integer.MIN_VALUE;
        }
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return Integer.MIN_VALUE;
        }
        if (r1 == n-1 && c1 == n-1) {
            return grid[r1][c1];
        }
        if (memo[r1][c1][r2] != Integer.MIN_VALUE) {
            return memo[r1][c1][r2];
        }
        int cherry = grid[r1][c1];
        if (r1 != r2 || c1 != c2) {
            cherry += grid[r2][c2];
        }
        int maxNext = Integer.MIN_VALUE;
        for (int nr1 : new int[]{r1+1, r1}) {
            for (int nr2 : new int[]{r2+1, r2}) {
                int nc1 = c1 + (nr1 - r1);
                int nc2 = c2 + (nr2 - r2);
                int val = dfs(grid, nr1, nc1, nr2, memo, n);
                if (val > maxNext) {
                    maxNext = val;
                }
            }
        }
        int res = cherry + maxNext;
        memo[r1][c1][r2] = res;
        return res;
    }
}
