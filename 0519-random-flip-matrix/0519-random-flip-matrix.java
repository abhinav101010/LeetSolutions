import java.util.*;

class Solution {
    private int m, n, total;
    private Map<Integer, Integer> map;
    private Random rand = new Random();

    public Solution(int m, int n) {
        this.m = m;
        this.n = n;
        this.total = m * n;
        this.map = new HashMap<>();
    }

    public int[] flip() {
        int r = rand.nextInt(total);
        total--;
        int idx = map.getOrDefault(r, r);
        map.put(r, map.getOrDefault(total, total));
        return new int[]{idx / n, idx % n};
    }

    public void reset() {
        total = m * n;
        map.clear();
    }
}