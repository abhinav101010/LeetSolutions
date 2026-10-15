import java.util.*;

class Solution {
    public boolean areSentencesSimilar(String[] words1, String[] words2, List<List<String>> pairs) {
        if (words1.length != words2.length) return false;
        Set<String> similar = new HashSet<>();
        for (List<String> p : pairs) {
            similar.add(p.get(0) + "#" + p.get(1));
            similar.add(p.get(1) + "#" + p.get(0));
        }
        for (int i = 0; i < words1.length; i++) {
            if (words1[i].equals(words2[i])) continue;
            if (!similar.contains(words1[i] + "#" + words2[i])) {
                return false;
            }
        }
        return true;
    }
}
