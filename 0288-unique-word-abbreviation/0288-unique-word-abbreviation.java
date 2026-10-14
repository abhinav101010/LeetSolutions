import java.util.*;

class ValidWordAbbr {
    private Map<String, Set<String>> map;

    public ValidWordAbbr(String[] dictionary) {
        map = new HashMap<>();
        for (String word : dictionary) {
            String abbr = abbreviate(word);
            map.computeIfAbsent(abbr, k -> new HashSet<>()).add(word);
        }
    }

    public boolean isUnique(String word) {
        String abbr = abbreviate(word);
        if (!map.containsKey(abbr)) {
            return true;
        }
        Set<String> set = map.get(abbr);
        return set.size() == 1 && set.contains(word);
    }

    private String abbreviate(String word) {
        int n = word.length();
        if (n <= 2) {
            return word;
        }
        return "" + word.charAt(0) + (n - 2) + word.charAt(n - 1);
    }
}
