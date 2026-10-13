import java.util.*;

class Solution {
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> graph = new HashMap<>();
        Map<Character, Integer> indegree = new HashMap<>();
        for (String w : words) {
            for (char c : w.toCharArray()) {
                indegree.putIfAbsent(c, 0);
                graph.putIfAbsent(c, new HashSet<>());
            }
        }
        for (int i = 0; i < words.length - 1; i++) {
            String w1 = words[i], w2 = words[i + 1];
            int minLen = Math.min(w1.length(), w2.length());
            for (int j = 0; j < minLen; j++) {
                char c1 = w1.charAt(j), c2 = w2.charAt(j);
                if (c1 != c2) {
                    if (!graph.get(c1).contains(c2)) {
                        graph.get(c1).add(c2);
                        indegree.put(c2, indegree.getOrDefault(c2, 0) + 1);
                    }
                    break;
                }
            }
            if (w1.length() > w2.length() && w1.startsWith(w2)) return "";
        }
        Queue<Character> q = new LinkedList<>();
        for (char c : indegree.keySet()) {
            if (indegree.get(c) == 0) q.add(c);
        }
        StringBuilder res = new StringBuilder();
        while (!q.isEmpty()) {
            char c = q.poll();
            res.append(c);
            for (char next : graph.get(c)) {
                indegree.put(next, indegree.get(next) - 1);
                if (indegree.get(next) == 0) q.add(next);
            }
        }
        if (res.length() != indegree.size()) return "";
        return res.toString();
    }
}