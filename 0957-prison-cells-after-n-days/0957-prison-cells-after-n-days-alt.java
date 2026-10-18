import java.util.*;
class Solution {
    public int[] prisonAfterNDays(int[] cells, int N) {
        Map<String, Integer> seen = new HashMap<>();
        while (N > 0) {
            String key = Arrays.toString(cells);
            if (seen.containsKey(key)) {
                int cycle = seen.get(key) - N;
                N %= cycle;
            } else {
                seen.put(key, N);
            }
            if (N == 0) break;
            int[] next = new int[8];
            for (int i = 1; i < 7; i++) {
                next[i] = (cells[i-1] == cells[i+1]) ? 1 : 0;
            }
            cells = next;
            N--;
        }
        return cells;
    }
}
