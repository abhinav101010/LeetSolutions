import java.util.*;

class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        if (!wordSet.contains(endWord)) return new ArrayList<>();
        
        Map<String, List<String>> graph = new HashMap<>();
        for (String word : wordSet) {
            for (int i = 0; i < word.length(); i++) {
                String pattern = word.substring(0, i) + '*' + word.substring(i + 1);
                graph.computeIfAbsent(pattern, k -> new ArrayList<>()).add(word);
            }
        }
        
        Map<String, List<List<String>>> level = new HashMap<>();
        level.put(beginWord, new ArrayList<>(List.of(List.of(beginWord))));
        Set<String> visited = new HashSet<>(List.of(beginWord));
        boolean found = false;
        
        while (!level.isEmpty() && !found) {
            Map<String, List<List<String>>> nextLevel = new HashMap<>();
            for (Map.Entry<String, List<List<String>>> entry : level.entrySet()) {
                String word = entry.getKey();
                List<List<String>> paths = entry.getValue();
                
                if (word.equals(endWord)) {
                    found = true;
                    return paths;
                }
                
                for (int i = 0; i < word.length(); i++) {
                    String pattern = word.substring(0, i) + '*' + word.substring(i + 1);
                    if (graph.containsKey(pattern)) {
                        for (String nei : graph.get(pattern)) {
                            if (!visited.contains(nei)) {
                                nextLevel.computeIfAbsent(nei, k -> new ArrayList<>());
                                for (List<String> path : paths) {
                                    List<String> newPath = new ArrayList<>(path);
                                    newPath.add(nei);
                                    nextLevel.get(nei).add(newPath);
                                }
                            }
                        }
                    }
                }
            }
            
            visited.addAll(nextLevel.keySet());
            level = nextLevel;
        }
        
        return new ArrayList<>();
    }
}