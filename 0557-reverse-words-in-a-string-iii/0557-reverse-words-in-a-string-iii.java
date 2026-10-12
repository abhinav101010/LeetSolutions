class Solution {
    public String reverseWords(String s) {
        StringBuilder result = new StringBuilder();
        String[] words = s.split(" ");
        for (int i = 0; i < words.length; i++) {
            StringBuilder wordRev = new StringBuilder(words[i]);
            wordRev.reverse();
            result.append(wordRev);
            if (i < words.length - 1) {
                result.append(" ");
            }
        }
        return result.toString();
    }
}