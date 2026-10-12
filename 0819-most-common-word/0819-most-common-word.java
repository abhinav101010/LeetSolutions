import java.util.*;
import java.util.regex.*;

class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> bannedSet = new HashSet<>(Arrays.asList(banned));
        Map<String, Integer> count = new HashMap<>();
        
        String[] words = paragraph.toLowerCase().split("[^a-z]+");
        
        for (String word : words) {
            if (!word.isEmpty() && !bannedSet.contains(word)) {
                count.put(word, count.getOrDefault(word, 0) + 1);
            }
        }
        
        String result = "";
        int maxCount = 0;
        for (Map.Entry<String, Integer> entry : count.entrySet()) {
            if (entry.getValue() > maxCount) {
                maxCount = entry.getValue();
                result = entry.getKey();
            }
        }
        return result;
    }
}