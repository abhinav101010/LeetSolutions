class Solution {
    public int minFallingPathSum(int[][] A) {
        int n = A.length;
        int[] dp = new int[n];
        System.arraycopy(A[0], 0, dp, 0, n);
        for (int r = 1; r < n; r++) {
            int[] newDp = new int[n];
            for (int c = 0; c < n; c++) {
                int best = dp[c];
                if (c > 0) best = Math.min(best, dp[c-1]);
                if (c < n-1) best = Math.min(best, dp[c+1]);
                newDp[c] = A[r][c] + best;
            }
            dp = newDp;
        }
        int min = dp[0];
        for (int v : dp) {
            if (v < min) min = v;
        }
        return min;
    }
}
