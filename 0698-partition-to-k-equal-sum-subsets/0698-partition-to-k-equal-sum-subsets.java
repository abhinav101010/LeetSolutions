import java.util.*;

class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int total = 0;
        for (int v : nums) total += v;
        if (total % k != 0) return false;
        int target = total / k;
        Arrays.sort(nums);
        // reverse
        for (int i = 0, j = nums.length - 1; i < j; i++, j--) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        if (nums[0] > target) return false;
        boolean[] used = new boolean[nums.length];
        return backtrack(nums, used, 0, k, 0, target);
    }
    
    private boolean backtrack(int[] nums, boolean[] used, int start, int kRemain, int curSum, int target) {
        if (kRemain == 0) return true;
        if (curSum == target) {
            return backtrack(nums, used, 0, kRemain - 1, 0, target);
        }
        for (int i = start; i < nums.length; i++) {
            if (!used[i] && curSum + nums[i] <= target) {
                used[i] = true;
                if (backtrack(nums, used, i + 1, kRemain, curSum + nums[i], target)) {
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
}
