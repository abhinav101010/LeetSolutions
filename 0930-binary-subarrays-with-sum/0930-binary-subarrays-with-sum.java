import java.util.*;
class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        Map<Integer, Integer> prefix = new HashMap<>();
        prefix.put(0, 1);
        int sum = 0;
        int ans = 0;
        for (int x : nums) {
            sum += x;
            ans += prefix.getOrDefault(sum - goal, 0);
            prefix.put(sum, prefix.getOrDefault(sum, 0) + 1);
        }
        return ans;
    }
}
