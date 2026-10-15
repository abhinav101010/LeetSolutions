import java.util.*;
class Solution {
    public boolean splitArraySameAverage(int[] nums) {
        int n = nums.length;
        int total = 0;
        for (int v : nums) total += v;
        // dp[k] = set of possible sums using k elements
        List<Set<Integer>> dp = new ArrayList<>();
        for (int k = 0; k <= n/2; k++) {
            dp.add(new HashSet<>());
        }
        dp.get(0).add(0);
        for (int num : nums) {
            for (int k = n/2; k >= 1; k--) {
                Set<Integer> prev = dp.get(k-1);
                Set<Integer> curr = dp.get(k);
                for (int sum : prev) {
                    curr.add(sum + num);
                }
            }
        }
        for (int k = 1; k <= n/2; k++) {
            if ((total * k) % n == 0) {
                int target = (total * k) / n;
                if (dp.get(k).contains(target)) {
                    return true;
                }
            }
        }
        return false;
    }
}
