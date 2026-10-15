import java.util.*;

class Solution {
    public int kSimilarity(String s1, String s2) {
        if (s1.equals(s2)) return 0;
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new ArrayDeque<>();
        queue.offer(s1);
        visited.add(s1);
        int steps = 0;
        int n = s1.length();
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String cur = queue.poll();
                int idx = 0;
                while (idx < n && cur.charAt(idx) == s2.charAt(idx)) {
                    idx++;
                }
                char[] arr = cur.toCharArray();
                for (int j = idx + 1; j < n; j++) {
                    if (arr[j] == s2.charAt(idx) && arr[j] != s2.charAt(j)) {
                        char tmp = arr[idx];
                        arr[idx] = arr[j];
                        arr[j] = tmp;
                        String nxt = new String(arr);
                        if (nxt.equals(s2)) {
                            return steps + 1;
                        }
                        if (!visited.contains(nxt)) {
                            visited.add(nxt);
                            queue.offer(nxt);
                        }
                        // backtrack
                        tmp = arr[idx];
                        arr[idx] = arr[j];
                        arr[j] = tmp;
                    }
                }
            }
            steps++;
        }
        return steps;
    }
}
