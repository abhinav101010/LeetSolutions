import java.util.HashMap;
import java.util.Map;
class Solution {
    private Map<Integer, Integer> memo = new HashMap<>();
    private int x;
    public int leastOpsExpressTarget(int x, int target) {
        this.x = x;
        return dfs(target);
    }
    private int dfs(int t) {
        if (t == 0) return 0;
        if (memo.containsKey(t)) return memo.get(t);
        if (t < x) {
            int ans = Math.min(2*t - 1, 2*(x - t));
            memo.put(t, ans);
            return ans;
        }
        int k = (int)(Math.log(t) / Math.log(x));
        long p = 1;
        for (int i = 0; i < k; i++) p *= x;
        int ans1 = Integer.MAX_VALUE;
        if (p <= t) {
            ans1 = k + dfs(t - (int)p);
        }
        long p2 = p * x;
        int ans2 = Integer.MAX_VALUE;
        if (p2 - t < t) {
            ans2 = (k+1) + dfs((int)(p2 - t));
        }
        int ans = Math.min(ans1, ans2);
        memo.put(t, ans);
        return ans;
    }
}
