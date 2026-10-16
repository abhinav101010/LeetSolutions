import java.util.*;
class Solution {
    public int largestUniqueNumber(int[] A) {
        Map<Integer, Integer> c = new HashMap<>();
        for (int x : A) c.put(x, c.getOrDefault(x, 0) + 1);
        int ans = -1;
        for (Map.Entry<Integer, Integer> e : c.entrySet()) {
            if (e.getValue() == 1) ans = Math.max(ans, e.getKey());
        }
        return ans;
    }
}
