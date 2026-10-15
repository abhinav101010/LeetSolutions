import java.util.*;

class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        if (hand.length % W != 0) return false;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int card : hand) {
            map.put(card, map.getOrDefault(card, 0) + 1);
        }
        while (!map.isEmpty()) {
            int first = map.firstKey();
            int count = map.get(first);
            for (int i = 0; i < W; i++) {
                int cur = first + i;
                if (!map.containsKey(cur) || map.get(cur) < count) {
                    return false;
                }
                map.put(cur, map.get(cur) - count);
                if (map.get(cur) == 0) {
                    map.remove(cur);
                }
            }
        }
        return true;
    }
}
