import java.util.*;

class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        count.put(0, 1);
        int prefixSum = 0;
        int result = 0;
        
        for (int num : nums) {
            prefixSum += num;
            result += count.getOrDefault(prefixSum - k, 0);
            count.put(prefixSum, count.getOrDefault(prefixSum, 0) + 1);
        }
        
        return result;
    }
}