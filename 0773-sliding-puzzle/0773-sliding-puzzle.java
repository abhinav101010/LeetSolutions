import java.util.*;

class Solution {
    public int slidingPuzzle(int[][] board) {
        StringBuilder sb = new StringBuilder();
        for (int[] row : board) {
            for (int num : row) {
                sb.append(num);
            }
        }
        String start = sb.toString();
        String target = "123450";
        if (start.equals(target)) return 0;
        int[][] neighbors = {
            {1,3},
            {0,2,4},
            {1,5},
            {0,4},
            {1,3,5},
            {2,4}
        };
        Deque<String> q = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();
        q.offer(start);
        visited.add(start);
        int steps = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                String cur = q.poll();
                if (cur.equals(target)) return steps;
                int zeroIdx = cur.indexOf('0');
                for (int nb : neighbors[zeroIdx]) {
                    char[] chars = cur.toCharArray();
                    char tmp = chars[zeroIdx];
                    chars[zeroIdx] = chars[nb];
                    chars[nb] = tmp;
                    String nxt = new String(chars);
                    if (!visited.contains(nxt)) {
                        visited.add(nxt);
                        q.offer(nxt);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
}
