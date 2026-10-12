import java.util.*;

class Solution {
    private Map<String, Integer> memo = new HashMap<>();
    private int[] handCount = new int[26];
    
    public int findMinStep(String board, String hand) {
        for (char c : hand.toCharArray()) {
            handCount[c - 'A']++;
        }
        return dfs(board);
    }
    
    private int dfs(String board) {
        board = clean(board);
        if (board.isEmpty()) return 0;
        if (memo.containsKey(board)) return memo.get(board);
        
        int ans = Integer.MAX_VALUE;
        int i = 0;
        while (i < board.length()) {
            int j = i;
            while (j < board.length() && board.charAt(j) == board.charAt(i)) j++;
            int need = 3 - (j - i);
            if (handCount[board.charAt(i) - 'A'] >= need) {
                handCount[board.charAt(i) - 'A'] -= need;
                int nextSteps = dfs(board.substring(0, i) + board.substring(j));
                if (nextSteps != -1) ans = Math.min(ans, nextSteps + need);
                handCount[board.charAt(i) - 'A'] += need;
            }
            i = j;
        }
        
        memo.put(board, ans == Integer.MAX_VALUE ? -1 : ans);
        return memo.get(board);
    }
    
    private String clean(String s) {
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (j < s.length() && s.charAt(j) == s.charAt(i)) j++;
            if (j - i >= 3) {
                return clean(s.substring(0, i) + s.substring(j));
            }
            i = j;
        }
        return s;
    }
}