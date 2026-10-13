import java.util.*;

class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> groups = new HashMap<>();
        for (String s : strings) {
            String key = getKey(s);
            groups.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(groups.values());
    }
    
    private String getKey(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i < s.length(); i++) {
            int diff = (s.charAt(i) - s.charAt(i - 1) + 26) % 26;
            sb.append(diff).append(',');
        }
        return sb.toString();
    }
}