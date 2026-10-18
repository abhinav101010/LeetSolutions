import java.util.*;

class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        List<Integer> result = new ArrayList<>();
        // Build map
        Map<Integer, List<Integer>> tree = new HashMap<>();
        for (int i = 0; i < pid.size(); i++) {
            int parent = ppid.get(i);
            tree.computeIfAbsent(parent, k -> new ArrayList<>()).add(pid.get(i));
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(kill);
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            result.add(cur);
            List<Integer> children = tree.get(cur);
            if (children != null) {
                for (int child : children) {
                    queue.offer(child);
                }
            }
        }
        return result;
    }
}
