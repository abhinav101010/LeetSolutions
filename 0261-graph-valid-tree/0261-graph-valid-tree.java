import java.util.*;

class Solution {
    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n - 1) return false;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        boolean[] visited = new boolean[n];
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(0);
        visited[0] = true;
        while (!stack.isEmpty()) {
            int cur = stack.pop();
            for (int next : graph.get(cur)) {
                if (!visited[next]) {
                    visited[next] = true;
                    stack.push(next);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return false;
        }
        return true;
    }
}