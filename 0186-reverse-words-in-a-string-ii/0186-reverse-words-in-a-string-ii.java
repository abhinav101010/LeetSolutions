class Solution {
    public void reverseWords(char[] s) {
        reverse(s, 0, s.length - 1);
        int l = 0;
        for (int r = 0; r < s.length; r++) {
            if (s[r] == ' ') {
                reverse(s, l, r - 1);
                l = r + 1;
            }
        }
        reverse(s, l, s.length - 1);
    }
    private void reverse(char[] s, int l, int r) {
        while (l < r) {
            char t = s[l]; s[l] = s[r]; s[r] = t;
            l++; r--;
        }
    }
}