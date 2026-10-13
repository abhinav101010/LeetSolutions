import java.util.*;

class Solution {
    public int shortestDistance(String[] wordsDict, String word1, String word2) {
        int i = -1, j = -1, res = wordsDict.length;
        for (int k = 0; k < wordsDict.length; k++) {
            if (wordsDict[k].equals(word1)) i = k;
            if (wordsDict[k].equals(word2)) j = k;
            if (i != -1 && j != -1) res = Math.min(res, Math.abs(i - j));
        }
        return res;
    }
}