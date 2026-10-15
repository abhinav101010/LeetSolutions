class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        int count = 0;
        for (String word : words) {
            if (isSubseq(s, word)) {
                count++;
            }
        }
        return count;
    }
    private boolean isSubseq(String s, String word) {
        int i = 0;
        for (char c : s.toCharArray()) {
            if (i < word.length() && word.charAt(i) == c) {
                i++;
            }
        }
        return i == word.length();
    }
}
