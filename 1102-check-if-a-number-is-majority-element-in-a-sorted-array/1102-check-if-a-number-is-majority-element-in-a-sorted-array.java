import java.util.*;
class Solution {
    public boolean isMajorityElement(int[] nums, int target) {
        int n = nums.length;
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        if (l >= n || nums[l] != target) return false;
        int cnt = 0;
        for (int i = l; i < n && nums[i] == target; i++) cnt++;
        return cnt > n / 2;
    }
}
