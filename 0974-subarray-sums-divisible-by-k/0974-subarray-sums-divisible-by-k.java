import java.util.*;
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        count.put(0, 1);
        int prefix = 0;
        int ans = 0;
        for (int num : nums) {
            prefix = (prefix % k + k) % k; // ensure non-negative
            ans += count.getOrDefault(prefix, 0);
            count.put(prefix, count.getOrDefault(prefix, 0) + 1);
        }
        return ans;
    }
}
