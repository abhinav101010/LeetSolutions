class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int[] orderMap = new int[26];
        for (int i = 0; i < order.length(); i++) {
            orderMap[order.charAt(i) - 'a'] = i;
        }
        for (int i = 0; i < words.length - 1; i++) {
            if (!lessEqual(words[i], words[i+1], orderMap)) {
                return false;
            }
        }
        return true;
    }
    private boolean lessEqual(String w1, String w2, int[] orderMap) {
        int len = Math.min(w1.length(), w2.length());
        for (int j = 0; j < len; j++) {
            int c1 = w1.charAt(j) - 'a';
            int c2 = w2.charAt(j) - 'a';
            if (c1 != c2) {
                return orderMap[c1] < orderMap[c2];
            }
        }
        return w1.length() <= w2.length();
    }
}
