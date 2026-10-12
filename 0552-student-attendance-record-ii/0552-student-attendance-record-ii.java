import java.util.*;

class Solution {
    private static final int MOD = 1000000007;
    private int[][][] memo;
    private int n;
    
    public int checkRecord(int n) {
        this.n = n;
        memo = new int[n + 1][2][3];
        for (int[][] layer : memo) {
            for (int[] row : layer) {
                Arrays.fill(row, -1);
            }
        }
        return dp(0, 0, 0);
    }
    
    private int dp(int i, int a, int l) {
        if (i == n) return 1;
        if (memo[i][a][l] != -1) return memo[i][a][l];
        
        long total = dp(i + 1, a, 0); // P
        if (a == 0) total = (total + dp(i + 1, 1, 0)) % MOD; // A
        if (l < 2) total = (total + dp(i + 1, a, l + 1)) % MOD; // L
        
        memo[i][a][l] = (int)total;
        return memo[i][a][l];
    }
}