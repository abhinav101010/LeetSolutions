import java.util.*;
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] cnt = new int[26];
        for (char c : chars.toCharArray()) cnt[c - 'a']++;
        int ans = 0;
        for (String w : words) {
            int[] wc = new int[26];
            boolean ok = true;
            for (char c : w.toCharArray()) {
                wc[c - 'a']++;
                if (wc[c - 'a'] > cnt[c - 'a']) { ok = false; break; }
            }
            if (ok) ans += w.length();
        }
        return ans;
    }
}
