import java.util.*;

class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;
        
        int m = matrix.length;
        int n = matrix[0].length;
        int[] dp = new int[n + 1];
        int maxSide = 0;
        int prev = 0;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = Math.min(dp[j], Math.min(dp[j - 1], prev)) + 1;
                    maxSide = Math.max(maxSide, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
            prev = 0;
        }
        
        return maxSide * maxSide;
    }
}