import java.util.*;

class Solution {
    public int lengthLongestPath(String input) {
        int maxLen = 0;
        Map<Integer, Integer> pathLen = new HashMap<>();
        pathLen.put(0, 0);
        
        for (String line : input.split("\n")) {
            String name = line.replaceFirst("^\\t*", "");
            int depth = line.length() - name.length();
            
            if (name.contains(".")) {
                maxLen = Math.max(maxLen, pathLen.get(depth) + name.length());
            } else {
                pathLen.put(depth + 1, pathLen.get(depth) + name.length() + 1);
            }
        }
        
        return maxLen;
    }
}