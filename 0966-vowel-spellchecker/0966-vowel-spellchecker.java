import java.util.*;
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> wordsPerfect = new HashSet<>(Arrays.asList(wordlist));
        Map<String, String> wordsCap = new HashMap<>();
        Map<String, String> wordsVow = new HashMap<>();
        for (String w : wordlist) {
            String wlow = w.toLowerCase();
            if (!wordsCap.containsKey(wlow)) {
                wordsCap.put(wlow, w);
            }
            String wdev = devowel(wlow);
            if (!wordsVow.containsKey(wdev)) {
                wordsVow.put(wdev, w);
            }
        }
        List<String> res = new ArrayList<>();
        for (String q : queries) {
            if (wordsPerfect.contains(q)) {
                res.add(q);
                continue;
            }
            String qlow = q.toLowerCase();
            if (wordsCap.containsKey(qlow)) {
                res.add(wordsCap.get(qlow));
                continue;
            }
            String qdev = devowel(qlow);
            if (wordsVow.containsKey(qdev)) {
                res.add(wordsVow.get(qdev));
                continue;
            }
            res.add("");
        }
        return res.toArray(new String[0]);
    }
    private String devowel(String s) {
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if ("aeiou".indexOf(c) >= 0) {
                sb.append('*');
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}
