import java.util.*;
class Solution {
    public int[] prisonAfterNDays(int[] cells, int n) {
        Map<String, Integer> seen = new HashMap<>();
        while (n > 0) {
            String key = Arrays.toString(cells);
            if (seen.containsKey(key)) {
                int cycle = seen.get(key) - n;
                n %= cycle;
            } else {
                seen.put(key, n);
            }
            if (n == 0) break;
            int[] next = new int[8];
            for (int i = 1; i < 7; i++) {
                next[i] = (cells[i-1] == cells[i+1]) ? 1 : 0;
            }
            cells = next;
            n--;
        }
        return cells;
    }
}
