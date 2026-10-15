class Solution {
    public int numTilings(int n) {
        final int MOD = 1000000007;
        if (n == 0) return 1;
        if (n == 1) return 1;
        long[] dp = new long[n + 1];
        long[] g = new long[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        g[0] = 0;
        g[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2] + 2 * g[i-2]) % MOD;
            g[i] = (g[i-1] + dp[i-1]) % MOD;
        }
        return (int) dp[n];
    }
}
