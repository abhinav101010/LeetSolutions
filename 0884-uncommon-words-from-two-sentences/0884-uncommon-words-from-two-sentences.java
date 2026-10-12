class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> count = new HashMap<>();
        for (String word : s1.split(" ")) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        for (String word : s2.split(" ")) {
            count.put(word, count.getOrDefault(word, 0) + 1);
        }
        
        List<String> ans = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : count.entrySet()) {
            if (entry.getValue() == 1) {
                ans.add(entry.getKey());
            }
        }
        
        return ans.toArray(new String[0]);
    }
}