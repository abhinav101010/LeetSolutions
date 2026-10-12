import java.util.*;

class Solution {
    private int[][] memo;
    private String s;
    
    public int strangePrinter(String s) {
        this.s = s;
        int n = s.length();
        memo = new int[n][n];
        for (int[] row : memo) Arrays.fill(row, -1);
        return dp(0, n - 1);
    }
    
    private int dp(int i, int j) {
        if (i > j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int res = dp(i, j - 1) + 1;
        for (int k = i; k < j; k++) {
            if (s.charAt(k) == s.charAt(j)) {
                res = Math.min(res, dp(i, k) + dp(k + 1, j - 1));
            }
        }
        memo[i][j] = res;
        return res;
    }
}