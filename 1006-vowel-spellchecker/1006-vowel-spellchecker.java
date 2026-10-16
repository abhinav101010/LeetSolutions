import java.util.*;
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> exact = new HashSet<>();
        Map<String, String> caseMap = new HashMap<>();
        Map<String, String> vowelMap = new HashMap<>();
        for (String word : wordlist) {
            exact.add(word);
            String lower = word.toLowerCase();
            if (!caseMap.containsKey(lower)) {
                caseMap.put(lower, word);
            }
            String vowelKey = devowel(lower);
            if (!vowelMap.containsKey(vowelKey)) {
                vowelMap.put(vowelKey, word);
            }
        }
        String[] res = new String[queries.length];
        for (int i = 0; i < queries.length; i++) {
            String q = queries[i];
            if (exact.contains(q)) {
                res[i] = q;
            } else {
                String lower = q.toLowerCase();
                if (caseMap.containsKey(lower)) {
                    res[i] = caseMap.get(lower);
                } else {
                    String vkey = devowel(lower);
                    if (vowelMap.containsKey(vkey)) {
                        res[i] = vowelMap.get(vkey);
                    } else {
                        res[i] = "";
                    }
                }
            }
        }
        return res;
    }
    private String devowel(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                sb.append('*');
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
