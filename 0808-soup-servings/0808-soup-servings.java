import java.util.HashMap;
import java.util.Map;
class Solution {
    public double soupServings(int n) {
        if (n >= 4800) {
            return 1.0;
        }
        Map<Long, Double> memo = new HashMap<>();
        return dp(n, n, memo);
    }
    private double dp(int a, int b, Map<Long, Double> memo) {
        if (a <= 0 && b <= 0) {
            return 0.5;
        }
        if (a <= 0) {
            return 1.0;
        }
        if (b <= 0) {
            return 0.0;
        }
        long key = (((long) a) << 20) | b;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }
        double res = 0.25 * (
            dp(a-100, b, memo) +
            dp(a-75, b-25, memo) +
            dp(a-50, b-50, memo) +
            dp(a-25, b-75, memo)
        );
        memo.put(key, res);
        return res;
    }
}
