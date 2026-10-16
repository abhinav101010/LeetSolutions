import java.util.*;
class Solution {
    public int minimumSemesters(int n, int[][] relations) {
        List<Integer>[] adj = new List[n];
        for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
        int[] indeg = new int[n];
        for (int[] r : relations) { adj[r[0]-1].add(r[1]-1); indeg[r[1]-1]++; }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) if (indeg[i] == 0) q.offer(i);
        int sem = 0, taken = 0;
        while (!q.isEmpty()) {
            sem++;
            int sz = q.size();
            for (int k = 0; k < sz; k++) {
                int u = q.poll();
                taken++;
                for (int v : adj[u]) {
                    indeg[v]--;
                    if (indeg[v] == 0) q.offer(v);
                }
            }
        }
        return taken == n ? sem : -1;
    }
}
