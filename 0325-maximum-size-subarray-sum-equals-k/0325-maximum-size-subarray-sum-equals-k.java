import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        Map<Integer, Integer> sumToIndex = new HashMap<>();
        sumToIndex.put(0, -1);
        int prefixSum = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];
            if (sumToIndex.containsKey(prefixSum - k)) {
                maxLen = Math.max(maxLen, i - sumToIndex.get(prefixSum - k));
            }
            if (!sumToIndex.containsKey(prefixSum)) {
                sumToIndex.put(prefixSum, i);
            }
        }
        return maxLen;
    }
}
