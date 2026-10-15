import java.util.*;

class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        int n = flights.length;
        int k = days[0].length;
        int[][] dp = new int[n][k];
        for (int[] row : dp) Arrays.fill(row, Integer.MIN_VALUE);
        // week 0
        for (int c = 0; c < n; c++) {
            if (c == 0 || flights[0][c] == 1) {
                dp[c][0] = days[c][0];
            }
        }
        for (int w = 1; w < k; w++) {
            for (int c = 0; c < n; c++) {
                int best = Integer.MIN_VALUE;
                for (int pc = 0; pc < n; pc++) {
                    if ((pc == c || flights[pc][c] == 1) && dp[pc][w-1] != Integer.MIN_VALUE) {
                        best = Math.max(best, dp[pc][w-1] + days[c][w]);
                    }
                }
                dp[c][w] = best;
            }
        }
        int ans = 0;
        for (int c = 0; c < n; c++) {
            ans = Math.max(ans, dp[c][k-1]);
        }
        return ans;
    }
}
