import java.util.*;

class Solution {
    public int findShortestSubArray(int[] nums) {
        Map<Integer, Integer> left = new HashMap<>();
        Map<Integer, Integer> right = new HashMap<>();
        Map<Integer, Integer> count = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int x = nums[i];
            if (!left.containsKey(x)) {
                left.put(x, i);
            }
            right.put(x, i);
            count.put(x, count.getOrDefault(x, 0) + 1);
        }
        int degree = 0;
        for (int v : count.values()) {
            if (v > degree) {
                degree = v;
            }
        }
        int ans = nums.length;
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            int x = entry.getKey();
            if (entry.getValue() == degree) {
                int len = right.get(x) - left.get(x) + 1;
                if (len < ans) {
                    ans = len;
                }
            }
        }
        return ans;
    }
}
