import java.util.*;
class Solution {
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int x : arr) {
            count.put(x, count.getOrDefault(x, 0) + 1);
        }
        List<Integer> keys = new ArrayList<>(count.keySet());
        keys.sort((a, b) -> {
            int absA = Math.abs(a), absB = Math.abs(b);
            if (absA != absB) return Integer.compare(absA, absB);
            return Integer.compare(a, b);
        });
        for (int x : keys) {
            int c = count.getOrDefault(x, 0);
            if (c == 0) continue;
            int doubleX = 2 * x;
            if (count.getOrDefault(doubleX, 0) < c) {
                return false;
            }
            count.put(doubleX, count.getOrDefault(doubleX, 0) - c);
        }
        return true;
    }
}
