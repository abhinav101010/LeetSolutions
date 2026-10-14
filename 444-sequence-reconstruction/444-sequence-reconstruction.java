import java.util.*;

class Solution {
    public boolean sequenceReconstruction(int[] org, List<List<Integer>> seqs) {
        int n = org.length;
        int[] pos = new int[n + 1];
        for (int i = 0; i < n; i++) {
            pos[org[i]] = i;
        }
        // Check that all numbers in seqs are within [1,n]
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        int[] indeg = new int[n + 1];
        boolean[] seen = new boolean[n + 1];
        for (List<Integer> seq : seqs) {
            for (int v : seq) {
                if (v < 1 || v > n) return false;
                seen[v] = true;
            }
            for (int i = 0; i < seq.size() - 1; i++) {
                int u = seq.get(i), v = seq.get(i+1);
                adj.get(u).add(v);
                indeg[v]++;
            }
        }
        // Ensure all numbers in org appear in seqs
        for (int v : org) {
            if (!seen[v]) return false;
        }
        // Topological sort with unique order
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (indeg[i] == 0) {
                q.offer(i);
            }
        }
        int idx = 0;
        while (!q.isEmpty()) {
            if (q.size() != 1) {
                return false;
            }
            int u = q.poll();
            if (org[idx] != u) {
                return false;
            }
            idx++;
            for (int v : adj.get(u)) {
                indeg[v]--;
                if (indeg[v] == 0) {
                    q.offer(v);
                }
            }
        }
        return idx == n;
    }
}
