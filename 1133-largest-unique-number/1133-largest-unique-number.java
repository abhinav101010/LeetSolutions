import java.util.*;

class Solution {
    public int largestUniqueNumber(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : nums) cnt.put(x, cnt.getOrDefault(x, 0) + 1);
        int ans = -1;
        for (Map.Entry<Integer, Integer> kv : cnt.entrySet()) {
            if (kv.getValue() == 1 && kv.getKey() > ans) ans = kv.getKey();
        }
        return ans;
    }
}