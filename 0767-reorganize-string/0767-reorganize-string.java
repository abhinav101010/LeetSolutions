import java.util.*;

class Solution {
    public String reorganizeString(String s) {
        int[] cnt = new int[26];
        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> Integer.compare(b[0], a[0])); // max freq
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                pq.offer(new int[]{cnt[i], i});
            }
        }
        StringBuilder sb = new StringBuilder();
        int[] prev = new int[]{-1, -1}; // freq, charIndex
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            sb.append((char)('a' + cur[1]));
            cur[0]--;
            if (prev[0] > 0) {
                pq.offer(prev);
            }
            prev = cur;
        }
        String res = sb.toString();
        if (res.length() != s.length()) {
            return "";
        }
        return res;
    }
}
