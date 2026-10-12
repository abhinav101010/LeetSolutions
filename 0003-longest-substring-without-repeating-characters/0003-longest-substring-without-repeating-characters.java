class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] last = new int[128];
        for (int i = 0; i < 128; i++) last[i] = -1;

        int start = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (last[c] >= start) start = last[c] + 1;
            last[c] = i;
            ans = Math.max(ans, i - start + 1);
        }

        return ans;
    }
}
