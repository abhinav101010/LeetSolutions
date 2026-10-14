import java.util.*;

class Solution {
    private int m;
    private Set<Integer> blackset;
    private Map<Integer, Integer> map;
    private Random rand;

    public Solution(int N, int[] blacklist) {
        m = N - blacklist.length;
        blackset = new HashSet<>();
        for (int b : blacklist) {
            if (b < m) {
                blackset.add(b);
            }
        }
        map = new HashMap<>();
        int j = m;
        for (int b : blacklist) {
            if (b >= m) {
                continue;
            }
            while (blackset.contains(j) || map.containsKey(j)) {
                j++;
            }
            map.put(b, j);
            j++;
        }
        rand = new Random();
    }

    public int pick() {
        int x = rand.nextInt(m);
        Integer mapped = map.get(x);
        return mapped == null ? x : mapped;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
