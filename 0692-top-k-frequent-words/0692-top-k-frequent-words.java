import java.util.*;

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> freq = new HashMap<>();
        for (String w : words) {
            freq.put(w, freq.getOrDefault(w, 0) + 1);
        }
        List<String> list = new ArrayList<>(freq.keySet());
        Collections.sort(list, (a, b) -> {
            int freqA = freq.get(a);
            int freqB = freq.get(b);
            if (freqA != freqB) {
                return freqB - freqA; // descending
            }
            return a.compareTo(b); // ascending lexicographically
        });
        return list.subList(0, k);
    }
}
