import java.util.*;

class WordDistance {
    private Map<String, List<Integer>> pos = new HashMap<>();
    public WordDistance(String[] wordsDict) {
        for (int i = 0; i < wordsDict.length; i++) {
            pos.computeIfAbsent(wordsDict[i], k -> new ArrayList<>()).add(i);
        }
    }
    public int shortest(String word1, String word2) {
        List<Integer> p1 = pos.get(word1), p2 = pos.get(word2);
        int i = 0, j = 0, res = Integer.MAX_VALUE;
        while (i < p1.size() && j < p2.size()) {
            res = Math.min(res, Math.abs(p1.get(i) - p2.get(j)));
            if (p1.get(i) < p2.get(j)) i++; else j++;
        }
        return res;
    }
}