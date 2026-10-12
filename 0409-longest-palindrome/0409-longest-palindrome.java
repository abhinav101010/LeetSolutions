class Solution {
    public int longestPalindrome(String s) {
        int[] count = new int[128];
        for (char c : s.toCharArray()) count[c]++;
        int ans = 0;
        boolean odd = false;
        for (int freq : count) {
            if (freq % 2 == 0) ans += freq;
            else { ans += freq - 1; odd = true; }
        }
        if (odd) ans += 1;
        return ans;
    }
}