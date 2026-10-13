class Solution {
    public int minCost(int[][] costs) {
        if (costs.length == 0) return 0;
        int[] dp = new int[3];
        for (int i = 0; i < 3; i++) dp[i] = costs[0][i];
        for (int i = 1; i < costs.length; i++) {
            int[] dpNew = new int[3];
            dpNew[0] = costs[i][0] + Math.min(dp[1], dp[2]);
            dpNew[1] = costs[i][1] + Math.min(dp[0], dp[2]);
            dpNew[2] = costs[i][2] + Math.min(dp[0], dp[1]);
            dp = dpNew;
        }
        return Math.min(dp[0], Math.min(dp[1], dp[2]));
    }
}