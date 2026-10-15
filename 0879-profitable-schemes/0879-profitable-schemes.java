class Solution {
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        final int MOD = 1000000007;
        int len = group.length;
        int[][] dp = new int[n + 1][minProfit + 1];
        dp[0][0] = 1;
        for (int k = 0; k < len; k++) {
            int g = group[k];
            int p = profit[k];
            for (int members = n; members >= g; members--) {
                for (int earn = minProfit; earn >= 0; earn--) {
                    int newEarn = Math.min(minProfit, earn + p);
                    dp[members][newEarn] = (dp[members][newEarn] + dp[members - g][earn]) % MOD;
                }
            }
        }
        int total = 0;
        for (int members = 0; members <= n; members++) {
            total = (total + dp[members][minProfit]) % MOD;
        }
        return total;
    }
}
