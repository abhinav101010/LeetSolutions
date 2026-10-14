import java.util.*;

class Solution {
    public boolean areSentencesSimilarTwo(List<String> words1, List<String> words2, List<List<String>> pairs) {
        if (words1.size() != words2.size()) return false;
        Map<String, String> parent = new HashMap<>();
        for (List<String> p : pairs) {
            union(p.get(0), p.get(1), parent);
        }
        for (int i = 0; i < words1.size(); i++) {
            String w1 = words1.get(i);
            String w2 = words2.get(i);
            if (w1.equals(w2)) continue;
            if (!find(w1, parent).equals(find(w2, parent))) {
                return false;
            }
        }
        return true;
    }
    
    private String find(String x, Map<String, String> parent) {
        if (!parent.containsKey(x)) {
            parent.put(x, x);
        }
        if (!parent.get(x).equals(x)) {
            parent.put(x, find(parent.get(x), parent));
        }
        return parent.get(x);
    }
    
    private void union(String a, String b, Map<String, String> parent) {
        String ra = find(a, parent);
        String rb = find(b, parent);
        if (!ra.equals(rb)) {
            parent.put(rb, ra);
        }
    }
}
