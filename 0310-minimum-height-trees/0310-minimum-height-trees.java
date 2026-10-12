import java.util.*;

class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        if (n <= 1) return Arrays.asList(0);
        
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        int[] degree = new int[n];
        
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        
        Queue<Integer> leaves = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) leaves.offer(i);
        }
        
        int remaining = n;
        while (remaining > 2) {
            int leavesCount = leaves.size();
            remaining -= leavesCount;
            for (int i = 0; i < leavesCount; i++) {
                int leaf = leaves.poll();
                for (int nei : graph.get(leaf)) {
                    degree[nei]--;
                    if (degree[nei] == 1) leaves.offer(nei);
                }
            }
        }
        
        List<Integer> result = new ArrayList<>();
        while (!leaves.isEmpty()) result.add(leaves.poll());
        return result;
    }
}