class Solution {
    public long maxAlternatingSum(int[] nums) {
        long dp0 = 0, dp1 = 0;
        long ans = 0;
        for (int x : nums) {
            long ndp0 = Math.max(dp0, dp1 + x);
            long ndp1 = Math.max(dp1, dp0 - x);
            dp0 = ndp0; dp1 = ndp1;
            if (dp0 > ans) ans = dp0;
            if (dp1 > ans) ans = dp1;
        }
        return ans;
    }
}
