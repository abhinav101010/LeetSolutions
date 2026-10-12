import java.util.*;

class Solution {
    public boolean canCross(int[] stones) {
        Set<Integer> stoneSet = new HashSet<>();
        for (int s : stones) stoneSet.add(s);
        
        Map<String, Boolean> memo = new HashMap<>();
        return dfs(0, 0, stones[stones.length - 1], stoneSet, memo);
    }
    
    private boolean dfs(int pos, int k, int target, Set<Integer> stoneSet, Map<String, Boolean> memo) {
        if (pos == target) return true;
        String key = pos + "," + k;
        if (memo.containsKey(key)) return memo.get(key);
        
        for (int step = k - 1; step <= k + 1; step++) {
            if (step > 0 && stoneSet.contains(pos + step)) {
                if (dfs(pos + step, step, target, stoneSet, memo)) {
                    memo.put(key, true);
                    return true;
                }
            }
        }
        
        memo.put(key, false);
        return false;
    }
}