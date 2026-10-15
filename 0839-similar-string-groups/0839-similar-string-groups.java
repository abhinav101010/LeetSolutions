import java.util.*;
class Solution {
    public int numSimilarGroups(String[] strs) {
        int n = strs.length;
        int[] parent = new int[n];
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (similar(strs[i], strs[j])) {
                    union(parent, rank, i, j);
                }
            }
        }
        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            set.add(find(parent, i));
        }
        return set.size();
    }
    private boolean similar(String a, String b) {
        if (a.equals(b)) return true;
        List<Integer> diff = new ArrayList<>();
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff.add(i);
                if (diff.size() > 2) return false;
            }
        }
        if (diff.size() != 2) return false;
        int i = diff.get(0);
        int j = diff.get(1);
        return a.charAt(i) == b.charAt(j) && a.charAt(j) == b.charAt(i);
    }
    private int find(int[] parent, int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    private void union(int[] parent, int[] rank, int x, int y) {
        int rx = find(parent, x);
        int ry = find(parent, y);
        if (rx == ry) return;
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[rx] > rank[ry]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
}
