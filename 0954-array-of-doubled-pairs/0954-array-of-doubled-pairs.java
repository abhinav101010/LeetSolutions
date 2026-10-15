import java.util.*;
class Solution {
    public boolean canReorderDoubled(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int v : arr) {
            cnt.put(v, cnt.getOrDefault(v, 0) + 1);
        }
        List<Integer> keys = new ArrayList<>(cnt.keySet());
        keys.sort((a, b) -> Integer.compare(Math.abs(a), Math.abs(b)));
        for (int x : keys) {
            if (cnt.getOrDefault(x, 0) > cnt.getOrDefault(2*x, 0)) {
                return false;
            }
            cnt.put(2*x, cnt.getOrDefault(2*x, 0) - cnt.getOrDefault(x, 0));
        }
        return true;
    }
}
