import java.util.*;

public class Solution {
    public boolean sequenceReconstruction(int[] nums, int[][] sequences) {
        int n = nums.length;
        Map<Integer, List<Integer>> graph = new HashMap<>();
        Map<Integer, Integer> indeg = new HashMap<>();
        for (int i = 1; i <= n; ++i) {
            indeg.put(i, 0);
            graph.put(i, new ArrayList<Integer>());
        }
        for (int[] seq : sequences) {
            for (int i = 0; i < seq.length - 1; ++i) {
                int prev = seq[i], curv = seq[i + 1];
                graph.get(prev).add(curv);
                indeg.put(curv, indeg.get(curv) + 1);
                indeg.put(prev, indeg.get(prev) - 1);
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (Map.Entry<Integer, Integer> e : indeg.entrySet()) {
            if (e.getValue() == 0) q.addLast(e.getKey());
        }
        if (q.size() != 1) return false;
        List<Integer> order = new ArrayList<>();
        while (!q.isEmpty()) {
            if (q.size() > 1) return false;
            int cur = q.pollFirst();
            order.add(cur);
            for (int nxt : graph.get(cur)) {
                indeg.put(nxt, indeg.get(nxt) - 1);
                if (indeg.get(nxt) == 0) q.addLast(nxt);
            }
        }
        if (order.size() != n) return false;
        for (int i = 0; i < n; ++i) {
            if (order.get(i) != nums[i]) return false;
        }
        return true;
    }
}
