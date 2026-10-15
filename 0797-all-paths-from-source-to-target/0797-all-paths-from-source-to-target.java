import java.util.*;
class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> result = new ArrayList<>();
        Deque<Integer> path = new ArrayDeque<>();
        path.addLast(0);
        dfs(0, graph.length - 1, graph, path, result);
        return result;
    }
    private void dfs(int u, int target, int[][] graph, Deque<Integer> path, List<List<Integer>> result) {
        if (u == target) {
            result.add(new ArrayList<>(path));
            return;
        }
        for (int v : graph[u]) {
            path.addLast(v);
            dfs(v, target, graph, path, result);
            path.removeLast();
        }
    }
}
