import java.util.*;

class Solution {
    private Map<String, Integer> memo = new HashMap<>();
    
    public int findRotateSteps(String ring, String key) {
        return dp(ring, key, 0, 0);
    }
    
    private int dp(String ring, String key, int i, int j) {
        if (j == key.length()) return 0;
        String memoKey = i + "," + j;
        if (memo.containsKey(memoKey)) return memo.get(memoKey);
        
        int minSteps = Integer.MAX_VALUE;
        for (int k = 0; k < ring.length(); k++) {
            if (ring.charAt(k) == key.charAt(j)) {
                int diff = Math.abs(k - i);
                int steps = Math.min(diff, ring.length() - diff) + 1;
                minSteps = Math.min(minSteps, steps + dp(ring, key, k, j + 1));
            }
        }
        
        memo.put(memoKey, minSteps);
        return minSteps;
    }
}