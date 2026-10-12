class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder ans = new StringBuilder();
        for (String word : words) {
            int wordWeight = 0;
            for (int i = 0; i < word.length(); i++) {
                wordWeight += weights[word.charAt(i) - 'a'];
            }
            ans.append((char) ('z' - (wordWeight % 26)));
        }
        return ans.toString();
    }
}