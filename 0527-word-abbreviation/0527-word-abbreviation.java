import java.util.*;

class Solution {
    public List<String> wordsAbbreviation(List<String> dict) {
        int n = dict.size();
        int[] prefix = new int[n];
        Arrays.fill(prefix, 1);
        List<String> res = new ArrayList<>(dict);
        boolean changed;
        do {
            changed = false;
            Map<String, List<Integer>> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String abbr = abbreviate(dict.get(i), prefix[i]);
                map.computeIfAbsent(abbr, k -> new ArrayList<>()).add(i);
            }
            for (List<Integer> list : map.values()) {
                if (list.size() > 1) {
                    changed = true;
                    for (int i : list) {
                        prefix[i]++;
                    }
                }
            }
        } while (changed);
        for (int i = 0; i < n; i++) {
            res.set(i, abbreviate(dict.get(i), prefix[i]));
        }
        return res;
    }
    
    private String abbreviate(String word, int len) {
        if (word.length() - len <= 2) {
            return word;
        }
        int num = word.length() - len - 1;
        return word.substring(0, len) + num + word.charAt(word.length() - 1);
    }
}
