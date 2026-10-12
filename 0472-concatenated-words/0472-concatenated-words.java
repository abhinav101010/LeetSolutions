import java.util.*;

class Solution {
    private Set<String> wordSet;
    private Map<String, Boolean> memo = new HashMap<>();
    
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        wordSet = new HashSet<>(Arrays.asList(words));
        List<String> result = new ArrayList<>();
        for (String word : words) {
            if (!word.isEmpty() && canForm(word)) {
                result.add(word);
            }
        }
        return result;
    }
    
    private boolean canForm(String word) {
        if (memo.containsKey(word)) return memo.get(word);
        for (int i = 1; i < word.length(); i++) {
            String prefix = word.substring(0, i);
            String suffix = word.substring(i);
            if (wordSet.contains(prefix) && (wordSet.contains(suffix) || canForm(suffix))) {
                memo.put(word, true);
                return true;
            }
        }
        memo.put(word, false);
        return false;
    }
}