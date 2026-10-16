import java.util.*;
class Solution {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x1 = stones[i][0], y1 = stones[i][1];
            for (int j = i+1; j < n; j++) {
                int x2 = stones[j][0], y2 = stones[j][1];
                if (x1 == x2 || y1 == y2) {
                    graph[i].add(j);
                    graph[j].add(i);
                }
            }
        }
        boolean[] visited = new boolean[n];
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                Deque<Integer> stack = new ArrayDeque<>();
                stack.push(i);
                visited[i] = true;
                while (!stack.isEmpty()) {
                    int u = stack.pop();
                    for (int v : graph[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            stack.push(v);
                        }
                    }
                }
                components++;
            }
        }
        return n - components;
    }
}
