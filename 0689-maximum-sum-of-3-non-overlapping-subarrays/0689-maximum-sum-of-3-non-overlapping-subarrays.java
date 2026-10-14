import java.util.*;

class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int m = n - k + 1;
        int[] w = new int[m];
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        w[0] = sum;
        for (int i = 1; i < m; i++) {
            sum += nums[i + k - 1] - nums[i - 1];
            w[i] = sum;
        }
        int[] left = new int[m];
        int best = 0;
        for (int i = 0; i < m; i++) {
            if (w[i] > w[best]) {
                best = i;
            }
            left[i] = best;
        }
        int[] right = new int[m];
        best = m - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (w[i] >= w[best]) {
                best = i;
            }
            right[i] = best;
        }
        int maxSum = -1;
        int[] ans = new int[3];
        for (int j = k; j < m - k; j++) {
            int i = left[j - k];
            int l = right[j + k];
            int total = w[i] + w[j] + w[l];
            if (total > maxSum) {
                maxSum = total;
                ans[0] = i;
                ans[1] = j;
                ans[2] = l;
            }
        }
        return ans;
    }
}
