class Solution {
    public double largestSumOfAverages(int[] nums, int k) {
        int n = nums.length;
        double[] prefix = new double[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        double[][] dp = new double[n + 1][k + 1];
        for (int i = 1; i <= n; i++) {
            dp[i][1] = prefix[i] / i;
        }
        for (int g = 2; g <= k; g++) {
            for (int i = g; i <= n; i++) {
                double best = 0.0;
                for (int j = g - 1; j < i; j++) {
                    double avg = (prefix[i] - prefix[j]) / (i - j);
                    double val = dp[j][g-1] + avg;
                    if (val > dp[i][g]) {
                        dp[i][g] = val;
                    }
                }
            }
        }
        return dp[n][k];
    }
}
