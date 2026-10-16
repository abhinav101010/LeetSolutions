import java.util.*;
class Solution {
    public int twoSumLessThanK(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0, r = nums.length-1, ans = -1;
        while (l < r) {
            int s = nums[l] + nums[r];
            if (s < k) { ans = Math.max(ans, s); l++; }
            else r--;
        }
        return ans;
    }
}
