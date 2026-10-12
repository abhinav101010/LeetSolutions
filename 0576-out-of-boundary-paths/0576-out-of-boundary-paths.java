import java.util.*;

class Solution {
    private static final int MOD = 1000000007;
    private int[][][] memo;
    private int m, n;
    
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this.m = m;
        this.n = n;
        memo = new int[m][n][maxMove + 1];
        for (int[][] layer : memo) {
            for (int[] row : layer) {
                Arrays.fill(row, -1);
            }
        }
        return dp(startRow, startColumn, maxMove);
    }
    
    private int dp(int i, int j, int moves) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (moves == 0) return 0;
        if (memo[i][j][moves] != -1) return memo[i][j][moves];
        
        long total = dp(i+1, j, moves-1);
        total = (total + dp(i-1, j, moves-1)) % MOD;
        total = (total + dp(i, j+1, moves-1)) % MOD;
        total = (total + dp(i, j-1, moves-1)) % MOD;
        
        memo[i][j][moves] = (int)total;
        return memo[i][j][moves];
    }
}