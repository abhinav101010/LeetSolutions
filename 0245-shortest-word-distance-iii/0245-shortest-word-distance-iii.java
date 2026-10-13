class Solution {
    public int shortestWordDistance(String[] wordsDict, String word1, String word2) {
        int res = wordsDict.length;
        for (int i = 0; i < wordsDict.length; i++) {
            if (wordsDict[i].equals(word1)) {
                for (int j = 0; j < wordsDict.length; j++) {
                    if (i != j && wordsDict[j].equals(word2)) {
                        res = Math.min(res, Math.abs(i - j));
                    }
                }
            }
        }
        return res;
    }
}