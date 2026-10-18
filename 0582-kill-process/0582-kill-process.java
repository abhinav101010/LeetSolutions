import java.util.*;

public class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        Map<Integer, List<Integer>> tree = new HashMap<>();
        int n = pid.size();
        for (int i = 0; i < n; ++i) {
            tree.computeIfAbsent(ppid.get(i), k -> new ArrayList<>()).add(pid.get(i));
        }
        List<Integer> res = new ArrayList<>();
        Deque<Integer> q = new ArrayDeque<>();
        q.addLast(kill);
        while (!q.isEmpty()) {
            int cur = q.pollFirst();
            res.add(cur);
            List<Integer> children = tree.get(cur);
            if (children != null) {
                for (int c : children) q.addLast(c);
            }
        }
        return res;
    }
}
