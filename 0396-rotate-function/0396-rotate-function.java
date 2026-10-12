import java.util.*;

class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        long total = 0;
        long curr = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            curr += (long) i * nums[i];
        }
        
        long maxVal = curr;
        for (int i = n - 1; i > 0; i--) {
            curr = curr + total - (long) n * nums[i];
            maxVal = Math.max(maxVal, curr);
        }
        
        return (int) maxVal;
    }
}