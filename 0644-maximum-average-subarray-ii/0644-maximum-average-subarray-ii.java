import java.util.*;

class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double lo = Integer.MAX_VALUE;
        double hi = Integer.MIN_VALUE;
        for (int x : nums) {
            if (x < lo) lo = x;
            if (x > hi) hi = x;
        }
        final double eps = 1e-5;
        while (hi - lo > eps) {
            double mid = (lo + hi) / 2.0;
            if (check(nums, k, mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;
    }

    private boolean check(int[] nums, int k, double avg) {
        int n = nums.length;
        double[] prefix = new double[n+1];
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i] - avg;
        }
        double minPrefix = 0.0;
        for (int i = k; i <= n; i++) {
            if (prefix[i] - minPrefix >= 0) {
                return true;
            }
            if (prefix[i-k+1] < minPrefix) {
                minPrefix = prefix[i-k+1];
            }
        }
        return false;
    }
}
