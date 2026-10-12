class Solution {
    public int numberOfSpecialChars(String word) {
        int ans = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (word.indexOf(c) >= 0 && word.indexOf(Character.toUpperCase(c)) >= 0) {
                if (word.lastIndexOf(c) < word.indexOf(Character.toUpperCase(c))) {
                    ans++;
                }
            }
        }
        return ans;
    }
}