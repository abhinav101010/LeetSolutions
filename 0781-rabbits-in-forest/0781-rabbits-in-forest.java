import java.util.*;

class Solution {
    public int numRabbits(int[] answers) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int a : answers) {
            cnt.put(a, cnt.getOrDefault(a, 0) + 1);
        }
        int total = 0;
        for (Map.Entry<Integer, Integer> e : cnt.entrySet()) {
            int x = e.getKey();
            int f = e.getValue();
            int groupSize = x + 1;
            int groups = (f + groupSize - 1) / groupSize; // ceil
            total += groups * groupSize;
        }
        return total;
    }
}
