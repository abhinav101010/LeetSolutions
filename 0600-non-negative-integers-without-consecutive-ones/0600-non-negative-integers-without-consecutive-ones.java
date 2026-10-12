import java.util.*;

class Solution {
    private int[][] memo;
    private int[] bits;
    
    public int findIntegers(int n) {
        List<Integer> bitList = new ArrayList<>();
        while (n > 0) {
            bitList.add(n & 1);
            n >>= 1;
        }
        Collections.reverse(bitList);
        bits = bitList.stream().mapToInt(i -> i).toArray();
        memo = new int[bits.length][2];
        for (int[] row : memo) Arrays.fill(row, -1);
        return dp(0, 0, true);
    }
    
    private int dp(int i, int prev, boolean tight) {
        if (i == bits.length) return 1;
        if (!tight && memo[i][prev] != -1) return memo[i][prev];
        
        int limit = tight ? bits[i] : 1;
        int total = 0;
        for (int d = 0; d <= limit; d++) {
            if (prev == 1 && d == 1) continue;
            total += dp(i + 1, d, tight && d == limit);
        }
        
        if (!tight) memo[i][prev] = total;
        return total;
    }
}