class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] rank = new int[26];
        for (int i = 0; i < 26; i++) {
            rank[order.charAt(i) - 'a'] = i;
        }
        for (int i = 0; i < words.length-1; i++) {
            if (!isLessOrEqual(words[i], words[i+1], rank)) {
                return false;
            }
        }
        return true;
    }
    private boolean isLessOrEqual(String s1, String s2, int[] rank) {
        int n = Math.min(s1.length(), s2.length());
        for (int i = 0; i < n; i++) {
            int c1 = rank[s1.charAt(i) - 'a'];
            int c2 = rank[s2.charAt(i) - 'a'];
            if (c1 < c2) return true;
            if (c1 > c2) return false;
        }
        return s1.length() <= s2.length();
    }
}
