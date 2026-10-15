import java.util.*;
class Solution {
    public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
        Map<Integer, Pair<String,String>> matches = new HashMap<>();
        int m = indices.length;
        for (int i = 0; i < m; i++) {
            int idx = indices[i];
            String src = sources[i];
            String tgt = targets[i];
            if (s.startsWith(src, idx)) {
                matches.put(idx, new Pair<>(src, tgt));
            }
        }
        StringBuilder sb = new StringBuilder();
        int i = 0;
        int n = s.length();
        while (i < n) {
            if (matches.containsKey(i)) {
                Pair<String,String> p = matches.get(i);
                sb.append(p.getValue());
                i += p.getKey().length();
            } else {
                sb.append(s.charAt(i));
                i++;
            }
        }
        return sb.toString();
    }
    // simple Pair class
    class Pair<U,V> {
        private U first;
        private V second;
        public Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }
        public U getKey() { return first; }
        public V getValue() { return second; }
    }
}
