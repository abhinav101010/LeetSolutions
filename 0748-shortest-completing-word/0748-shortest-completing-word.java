import java.util.*;

class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int[] lpCount = new int[26];
        for (char c : licensePlate.toLowerCase().toCharArray()) {
            if (Character.isLetter(c)) {
                lpCount[c - 'a']++;
            }
        }
        
        String best = null;
        int bestLen = Integer.MAX_VALUE;
        for (String w : words) {
            int[] wc = new int[26];
            for (char c : w.toLowerCase().toCharArray()) {
                wc[c - 'a']++;
            }
            boolean ok = true;
            for (int i = 0; i < 26; i++) {
                if (wc[i] < lpCount[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                if (w.length() < bestLen) {
                    bestLen = w.length();
                    best = w;
                }
            }
        }
        return best;
    }
}
