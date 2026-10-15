import java.util.*;

class Solution {
    public int orderOfLargestPlusSign(int n, int[][] mines) {
        int[][] dp = new int[n][n];
        for (int[] row : dp) Arrays.fill(row, n);
        boolean[][] mine = new boolean[n][n];
        for (int[] m : mines) {
            mine[m[0]][m[1]] = true;
            dp[m[0]][m[1]] = 0;
        }
        // left to right
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mine[i][j]) {
                    cnt = 0;
                } else {
                    cnt++;
                }
                dp[i][j] = Math.min(dp[i][j], cnt);
            }
        }
        // right to left
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n-1; j >= 0; j--) {
                if (mine[i][j]) {
                    cnt = 0;
                } else {
                    cnt++;
                }
                dp[i][j] = Math.min(dp[i][j], cnt);
            }
        }
        // top to bottom
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (mine[i][j]) {
                    cnt = 0;
                } else {
                    cnt++;
                }
                dp[i][j] = Math.min(dp[i][j], cnt);
            }
        }
        // bottom to top
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = n-1; i >= 0; i--) {
                if (mine[i][j]) {
                    cnt = 0;
                } else {
                    cnt++;
                }
                dp[i][j] = Math.min(dp[i][j], cnt);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = Math.max(ans, dp[i][j]);
            }
        }
        return ans;
    }
}
