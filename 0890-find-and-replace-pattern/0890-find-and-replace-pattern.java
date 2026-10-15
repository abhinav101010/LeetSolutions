import java.util.*;
class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<Integer> patNorm = normalize(pattern);
        List<String> res = new ArrayList<>();
        for (String w : words) {
            if (normalize(w).equals(patNorm)) {
                res.add(w);
            }
        }
        return res;
    }
    private List<Integer> normalize(String s) {
        Map<Character, Integer> map = new HashMap<>();
        List<Integer> res = new ArrayList<>();
        for (char ch : s.toCharArray()) {
            if (!map.containsKey(ch)) {
                map.put(ch, map.size());
            }
            res.add(map.get(ch));
        }
        return res;
    }
}
