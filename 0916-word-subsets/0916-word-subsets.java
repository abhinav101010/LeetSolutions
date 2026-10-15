import java.util.*;
class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int[] need = new int[26];
        for (String b : B) {
            int[] cnt = new int[26];
            for (char ch : b.toCharArray()) {
                cnt[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                need[i] = Math.max(need[i], cnt[i]);
            }
        }
        List<String> res = new ArrayList<>();
        for (String a : A) {
            int[] cnt = new int[26];
            for (char ch : a.toCharArray()) {
                cnt[ch - 'a']++;
            }
            boolean ok = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < need[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                res.add(a);
            }
        }
        return res;
    }
}
