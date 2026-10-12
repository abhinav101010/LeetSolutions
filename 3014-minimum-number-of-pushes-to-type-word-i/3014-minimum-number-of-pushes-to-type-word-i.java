import java.util.*;

class Solution {
    public int minimumPushes(String word) {
        int[] count = new int[26];
        for (int i = 0; i < word.length(); i++) {
            count[word.charAt(i) - 'a']++;
        }
        Arrays.sort(count);
        // reverse so largest frequencies get the smallest push count
        for (int i = 0, j = 25; i < j; i++, j--) {
            int tmp = count[i]; count[i] = count[j]; count[j] = tmp;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int pushes = i / 8 + 1;
            ans += count[i] * pushes;
        }
        return ans;
    }
}