import java.util.*;

class Solution {
    public int maxCoins(int[] nums) {
        List<Integer> newNums = new ArrayList<>();
        newNums.add(1);
        for (int x : nums) if (x > 0) newNums.add(x);
        newNums.add(1);
        
        int n = newNums.size();
        int[][] dp = new int[n][n];
        
        for (int len = 2; len < n; len++) {
            for (int left = 0; left + len < n; left++) {
                int right = left + len;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = Math.max(dp[left][right],
                        newNums.get(left) * newNums.get(i) * newNums.get(right) + dp[left][i] + dp[i][right]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
}