import java.util.*;

class Solution {
    public boolean splitArray(int[] nums) {
        int n = nums.length;
        if (n < 7) return false;
        int[] prefix = new int[n+1];
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        for (int j = 3; j < n-3; j++) {
            Set<Integer> leftSums = new HashSet<>();
            for (int i = 1; i < j-1; i++) {
                int sum1 = prefix[i] - prefix[0];
                int sum2 = prefix[j] - prefix[i+1];
                if (sum1 == sum2) {
                    leftSums.add(sum1);
                }
            }
            for (int k = j+2; k < n-1; k++) {
                int sum3 = prefix[k] - prefix[j+1];
                int sum4 = prefix[n] - prefix[k+1];
                if (sum3 == sum4 && leftSums.contains(sum3)) {
                    return true;
                }
            }
        }
        return false;
    }
}
