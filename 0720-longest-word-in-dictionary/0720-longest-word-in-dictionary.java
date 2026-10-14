import java.util.*;

class Solution {
    public String longestWord(String[] words) {
        Set<String> set = new HashSet<>(Arrays.asList(words));
        set.add(""); // empty string as base
        List<String> list = new ArrayList<>(set);
        list.sort((a, b) -> {
            if (a.length() != b.length()) {
                return b.length() - a.length(); // descending length
            }
            return a.compareTo(b); // ascending lexicographically
        });
        for (String w : list) {
            boolean ok = true;
            for (int i = 1; i <= w.length(); i++) {
                if (!set.contains(w.substring(0, i))) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return w;
            }
        }
        return "";
    }
}
