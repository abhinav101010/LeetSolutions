import java.util.*;

class Solution {
    public int findPairs(int[] nums, int k) {
        if (k < 0) return 0;
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) count.put(num, count.getOrDefault(num, 0) + 1);
        
        int result = 0;
        if (k == 0) {
            for (int v : count.values()) {
                if (v > 1) result++;
            }
        } else {
            for (int num : count.keySet()) {
                if (count.containsKey(num + k)) result++;
            }
        }
        return result;
    }
}