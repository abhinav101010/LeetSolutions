import java.util.*;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        Map<Integer, Integer> modMap = new HashMap<>();
        modMap.put(0, -1);
        int prefixSum = 0;
        
        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];
            int mod = prefixSum % k;
            if (modMap.containsKey(mod)) {
                if (i - modMap.get(mod) >= 2) return true;
            } else {
                modMap.put(mod, i);
            }
        }
        
        return false;
    }
}