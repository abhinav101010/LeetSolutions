import java.util.*;

class Solution {
    private Map<Integer, Boolean> memo = new HashMap<>();
    private int maxChoosable;
    private int desired;

    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        this.maxChoosable = maxChoosableInteger;
        this.desired = desiredTotal;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        return dfs(0, 0);
    }

    private boolean dfs(int used, int total) {
        if (memo.containsKey(used)) return memo.get(used);
        
        for (int i = 1; i <= maxChoosable; i++) {
            if ((used & (1 << i)) == 0) {
                if (total + i >= desired || !dfs(used | (1 << i), total + i)) {
                    memo.put(used, true);
                    return true;
                }
            }
        }
        
        memo.put(used, false);
        return false;
    }
}