import java.util.*;

class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> count = new HashMap<>();
        for (char c : s.toCharArray()) {
            count.put(c, count.getOrDefault(c, 0) + 1);
        }
        
        List<Character> chars = new ArrayList<>(count.keySet());
        chars.sort((a, b) -> count.get(b) - count.get(a));
        
        StringBuilder sb = new StringBuilder();
        for (char c : chars) {
            for (int i = 0; i < count.get(c); i++) {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}