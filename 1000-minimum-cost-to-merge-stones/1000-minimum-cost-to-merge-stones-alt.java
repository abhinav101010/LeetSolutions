import java.util.*;
class Solution {
    private int[][][] dp;
    private int[] prefix;
    private int k, n;
    public int mergeStones(int[] stones, int k) {
        n = stones.length;
        this.k = k;
        if ((n - 1) % (k - 1) != 0) return -1;
        prefix = new int[n + 1];
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stones[i];
        dp = new int[n][n][k + 1];
        for (int i=0;i<n;i++) for (int j=0;j<n;j++) Arrays.fill(dp[i][j], -1);
        return dfs(0, n - 1, 1);
    }
    private int dfs(int i, int j, int m) {
        if (dp[i][j][m] != -1) return dp[i][j][m];
        if (i == j) return m == 1 ? 0 : 1000000000;
        if (m == 1) {
            int res = dfs(i, j, k) + (prefix[j + 1] - prefix[i]);
            dp[i][j][m] = res;
            return res;
        }
        int res = 1000000000;
        for (int p = i; p < j; p += k - 1) {
            res = Math.min(res, dfs(i, p, 1) + dfs(p + 1, j, m - 1));
        }
        dp[i][j][m] = res;
        return res;
    }
}
