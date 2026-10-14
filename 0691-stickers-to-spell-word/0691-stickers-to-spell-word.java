import java.util.*;
import java.util.Map.Entry;

class Solution {
    public int minStickers(String[] stickers, String target) {
        // Count letters in target
        int[] targetCount = new int[26];
        for (char c : target.toCharArray()) {
            targetCount[c - 'a']++;
        }
        // List of letters that appear in target
        List<Character> letters = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            if (targetCount[i] > 0) {
                letters.add((char)('a' + i));
            }
        }
        if (letters.isEmpty()) {
            return 0;
        }
        // Preprocess stickers: only keep counts for letters in target
        List<int[]> stickersCounts = new ArrayList<>();
        for (String s : stickers) {
            int[] cnt = new int[26];
            for (char c : s.toCharArray()) {
                cnt[c - 'a']++;
            }
            // Filter to only letters in target
            boolean has = false;
            int[] filtered = new int[26];
            for (char c : letters) {
                int idx = c - 'a';
                if (cnt[idx] > 0) {
                    filtered[idx] = cnt[idx];
                    has = true;
                }
            }
            if (has) {
                stickersCounts.add(filtered);
            }
        }
        if (stickersCounts.isEmpty()) {
            return -1;
        }
        // Map from state string to min stickers
        Map<String, Integer> memo = new HashMap<>();
        // Initial state string
        StringBuilder sb = new StringBuilder();
        for (char c : letters) {
            sb.append(targetCount[c - 'a']).append(',');
        }
        String initial = sb.toString();
        int res = dp(initial, targetCount, letters, stickersCounts, memo);
        return res == Integer.MAX_VALUE ? -1 : res;
    }
    
    private int dp(String state, int[] targetCount, List<Character> letters, List<int[]> stickersCounts, Map<String, Integer> memo) {
        if (memo.containsKey(state)) {
            return memo.get(state);
        }
        // Parse state to get current counts
        String[] parts = state.split(",");
        int[] curr = new int[26];
        int idx = 0;
        for (char c : letters) {
            curr[c - 'a'] = Integer.parseInt(parts[idx++]);
        }
        // Check if done
        boolean done = true;
        for (int v : curr) {
            if (v > 0) {
                done = false;
                break;
            }
        }
        if (done) {
            memo.put(state, 0);
            return 0;
        }
        int ans = Integer.MAX_VALUE;
        // Find first character with positive count
        char first = 0;
        for (char c : letters) {
            if (curr[c - 'a'] > 0) {
                first = c;
                break;
            }
        }
        for (int[] sticker : stickersCounts) {
            if (sticker[first - 'a'] == 0) {
                continue; // skip if doesn't help with first letter
            }
            int[] next = curr.clone();
            for (int i = 0; i < 26; i++) {
                if (sticker[i] > 0) {
                    next[i] = Math.max(0, next[i] - sticker[i]);
                }
            }
            // Build next state string
            StringBuilder sb = new StringBuilder();
            for (char c : letters) {
                sb.append(next[c - 'a']).append(',');
            }
            String nextState = sb.toString();
            ans = Math.min(ans, 1 + dp(nextState, targetCount, letters, stickersCounts, memo));
        }
        memo.put(state, ans);
        return ans;
    }
}
