import java.util.*;

class Solution {
    public boolean isPossible(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int n : nums) count.put(n, count.getOrDefault(n, 0) + 1);
        
        Map<Integer, Integer> tails = new HashMap<>();
        for (int n : nums) {
            if (count.getOrDefault(n, 0) == 0) continue;
            if (tails.getOrDefault(n - 1, 0) > 0) {
                tails.put(n - 1, tails.getOrDefault(n - 1, 0) - 1);
                tails.put(n, tails.getOrDefault(n, 0) + 1);
            } else if (count.getOrDefault(n + 1, 0) > 0 && count.getOrDefault(n + 2, 0) > 0) {
                count.put(n + 1, count.getOrDefault(n + 1, 0) - 1);
                count.put(n + 2, count.getOrDefault(n + 2, 0) - 1);
                tails.put(n + 2, tails.getOrDefault(n + 2, 0) + 1);
            } else {
                return false;
            }
            count.put(n, count.getOrDefault(n, 0) - 1);
        }
        return true;
    }
}