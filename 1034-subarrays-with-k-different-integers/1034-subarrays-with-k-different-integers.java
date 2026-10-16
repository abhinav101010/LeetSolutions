import java.util.*;
class Solution {
    private int atMost(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        int l = 0, res = 0;
        for (int r = 0; r < nums.length; r++) {
            count.put(nums[r], count.getOrDefault(nums[r], 0) + 1);
            while (count.size() > k) {
                int c = count.get(nums[l]);
                if (c == 1) count.remove(nums[l]);
                else count.put(nums[l], c - 1);
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
    public int subarraysWithKDistinct(int[] nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
}
