import java.util.*;

public class Solution {
    public boolean splitArray(int[] nums) {
        int n = nums.length;
        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int j = 3; j < n - 1; ++j) {
            Set<Integer> set = new HashSet<>();
            for (int i = 1; i < j - 1; ++i) {
                if (sum[i] == sum[j] - sum[i + 1]) {
                    set.add(sum[i]);
                }
            }
            for (int k = j + 2; k < n; ++k) {
                if (sum[n] - sum[k + 1] == sum[k] - sum[j + 1] && set.contains(sum[n] - sum[k + 1])) {
                    return true;
                }
            }
        }
        return false;
    }
}
