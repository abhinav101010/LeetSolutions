import java.util.*;

class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        Map<Integer, Integer> dp = new HashMap<>();
        dp.put(0, 1);
        
        for (int num : nums) {
            Map<Integer, Integer> nextDp = new HashMap<>();
            for (Map.Entry<Integer, Integer> entry : dp.entrySet()) {
                int sum = entry.getKey();
                int count = entry.getValue();
                nextDp.put(sum + num, nextDp.getOrDefault(sum + num, 0) + count);
                nextDp.put(sum - num, nextDp.getOrDefault(sum - num, 0) + count);
            }
            dp = nextDp;
        }
        
        return dp.getOrDefault(target, 0);
    }
}