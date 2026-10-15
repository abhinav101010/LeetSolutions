import java.util.*;

class Solution {
    public int longestLine(int[][] M) {
        if (M == null || M.length == 0 || M[0].length == 0) return 0;
        int rows = M.length, cols = M[0].length;
        int[][][] dp = new int[rows][cols][4];
        int ans = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (M[i][j] == 1) {
                    dp[i][j][0] = (j>0 ? dp[i][j-1][0] : 0) + 1;
                    dp[i][j][1] = (i>0 ? dp[i-1][j][1] : 0) + 1;
                    dp[i][j][2] = (i>0 && j>0 ? dp[i-1][j-1][2] : 0) + 1;
                    dp[i][j][3] = (i>0 && j+1<cols ? dp[i-1][j+1][3] : 0) + 1;
                    ans = Math.max(ans, Math.max(Math.max(dp[i][j][0], dp[i][j][1]), Math.max(dp[i][j][2], dp[i][j][3])));
                }
            }
        }
        return ans;
    }
}
