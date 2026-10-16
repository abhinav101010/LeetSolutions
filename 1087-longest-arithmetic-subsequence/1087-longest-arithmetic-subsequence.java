import java.util.*;
class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        Map<Integer,Integer>[] dp = new Map[n];
        for (int i = 0; i < n; i++) dp[i] = new HashMap<>();
        int ans = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; i++) {
                int d = nums[j] - nums[i];
                dp[j].put(d, dp[i].getOrDefault(d, 1) + 1);
                ans = Math.max(ans, dp[j].get(d));
            }
        }
        return ans;
    }
}
