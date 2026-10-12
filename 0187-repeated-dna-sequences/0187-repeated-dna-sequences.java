import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Map<String, Integer> count = new HashMap<>();
        List<String> result = new ArrayList<>();
        for (int i = 0; i + 10 <= s.length(); i++) {
            String seq = s.substring(i, i + 10);
            count.put(seq, count.getOrDefault(seq, 0) + 1);
            if (count.get(seq) == 2) result.add(seq);
        }
        return result;
    }
}