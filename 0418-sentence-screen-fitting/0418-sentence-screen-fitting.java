import java.util.*;

class Solution {
    public int wordsTyping(String[] sentence, int rows, int cols) {
        String s = String.join(" ", sentence) + " ";
        int n = s.length();
        int[] dp = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == ' ') {
                dp[i] = 1;
            } else if (i + cols >= n) {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + cols] + 1;
            }
        }
        int res = 0;
        int pos = 0;
        for (int i = 0; i < rows; i++) {
            res += dp[pos];
            pos = (pos + cols) % n;
            while (pos < n && s.charAt(pos) == ' ') pos++;
            if (pos == n) pos = 0;
        }
        return res / sentence.length;
    }
}