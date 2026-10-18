import java.util.*;

class Solution {
    public int minimumSemesters(int n, int[][] relations) {
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i <= n; i++) g.add(new ArrayList<>());
        int[] indeg = new int[n + 1];
        for (int[] r : relations) {
            g.get(r[0]).add(r[1]);
            indeg[r[1]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) q.offer(i);
        }
        int ans = 0, taken = 0;
        while (!q.isEmpty()) {
            ans++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.poll();
                taken++;
                for (int v : g.get(u)) {
                    if (--indeg[v] == 0) q.offer(v);
                }
            }
        }
        return taken == n ? ans : -1;
    }
}