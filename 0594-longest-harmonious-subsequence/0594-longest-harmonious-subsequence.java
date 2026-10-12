import java.util.*;

class Solution {
    public int findLHS(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int num : nums) count.put(num, count.getOrDefault(num, 0) + 1);
        
        int maxLen = 0;
        for (int num : count.keySet()) {
            if (count.containsKey(num + 1)) {
                maxLen = Math.max(maxLen, count.get(num) + count.get(num + 1));
            }
        }
        return maxLen;
    }
}