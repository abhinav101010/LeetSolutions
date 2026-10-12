import java.util.*;

class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        Map<Integer, Integer> edges = new HashMap<>();
        for (List<Integer> row : wall) {
            int pos = 0;
            for (int i = 0; i < row.size() - 1; i++) {
                pos += row.get(i);
                edges.put(pos, edges.getOrDefault(pos, 0) + 1);
            }
        }
        int maxEdges = 0;
        for (int v : edges.values()) maxEdges = Math.max(maxEdges, v);
        return wall.size() - maxEdges;
    }
}