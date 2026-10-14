import java.util.*;

class Solution {
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        Map<String, Set<Character>> map = new HashMap<>();
        for (String a : allowed) {
            String key = a.substring(0, 2);
            map.computeIfAbsent(key, k -> new HashSet<>()).add(a.charAt(2));
        }
        Set<String> seen = new HashSet<>();
        return dfs(bottom, map, seen);
    }
    
    private boolean dfs(String bottom, Map<String, Set<Character>> map, Set<String> seen) {
        if (bottom.length() == 1) return true;
        if (seen.contains(bottom)) return false;
        seen.add(bottom);
        // list of options for each position
        List<List<Character>> options = new ArrayList<>();
        for (int i = 0; i < bottom.length() - 1; i++) {
            String key = bottom.substring(i, i+2);
            Set<Character> set = map.get(key);
            if (set == null) return false;
            options.add(new ArrayList<>(set));
        }
        // backtrack to build next row
        return backtrack(options, 0, new StringBuilder(), map, seen);
    }
    
    private boolean backtrack(List<List<Character>> options, int idx, StringBuilder curr, 
                              Map<String, Set<Character>> map, Set<String> seen) {
        if (idx == options.size()) {
            String next = curr.toString();
            return dfs(next, map, seen);
        }
        for (char c : options.get(idx)) {
            curr.append(c);
            if (backtrack(options, idx+1, curr, map, seen)) {
                return true;
            }
            curr.deleteCharAt(curr.length()-1);
        }
        return false;
    }
}
