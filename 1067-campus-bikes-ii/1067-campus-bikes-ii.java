import java.util.*;
class Solution {
    public int assignBikes(int[][] workers, int[][] bikes) {
        int n = workers.length, m = bikes.length;
        Map<String, Integer> memo = new HashMap<>();
        return dp(workers, bikes, 0, 0, memo);
    }
    private int dp(int[][] workers, int[][] bikes, int i, int mask, Map<String,Integer> memo) {
        int n = workers.length, m = bikes.length;
        if (i == n) return 0;
        String key = i + "," + mask;
        if (memo.containsKey(key)) return memo.get(key);
        int best = Integer.MAX_VALUE;
        for (int j = 0; j < m; j++) {
            if ((mask >> j & 1) == 1) continue;
            int dist = Math.abs(workers[i][0]-bikes[j][0]) + Math.abs(workers[i][1]-bikes[j][1]);
            best = Math.min(best, dist + dp(workers, bikes, i+1, mask | (1<<j), memo));
        }
        memo.put(key, best);
        return best;
    }
}
