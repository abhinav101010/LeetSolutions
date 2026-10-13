import java.util.*;

class Solution {
    private Map<String, Boolean> memo = new HashMap<>();
    
    public boolean canWin(String currentState) {
        if (memo.containsKey(currentState)) return memo.get(currentState);
        char[] s = currentState.toCharArray();
        for (int i = 0; i < s.length - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                String next = new String(s);
                if (!canWin(next)) {
                    memo.put(currentState, true);
                    s[i] = '+';
                    s[i + 1] = '+';
                    return true;
                }
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        memo.put(currentState, false);
        return false;
    }
}