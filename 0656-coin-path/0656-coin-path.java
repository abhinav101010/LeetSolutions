import java.util.*;

class Solution {
    public List<Integer> cheapestJump(int[] A, int B) {
        int n = A.length;
        if (n == 0 || A[0] == -1 || A[n-1] == -1) {
            return new ArrayList<>();
        }
        final long INF = Long.MAX_VALUE;
        long[] dpCost = new long[n];
        List<Integer>[] dpPath = new ArrayList[n];
        Arrays.fill(dpCost, INF);
        for (int i = 0; i < n; i++) {
            dpPath[i] = new ArrayList<>();
        }
        dpCost[0] = A[0];
        dpPath[0].add(1); // 1-indexed
        for (int i = 1; i < n; i++) {
            if (A[i] == -1) continue;
            for (int j = Math.max(0, i - B); j < i; j++) {
                if (dpCost[j] == INF) continue;
                long candCost = dpCost[j] + A[i];
                List<Integer> candPath = new ArrayList<>(dpPath[j]);
                candPath.add(i + 1);
                if (candCost < dpCost[i]) {
                    dpCost[i] = candCost;
                    dpPath[i] = candPath;
                } else if (candCost == dpCost[i]) {
                    // compare lexicographically
                    if (isLexicographicallySmaller(candPath, dpPath[i])) {
                        dpPath[i] = candPath;
                    }
                }
            }
        }
        if (dpCost[n-1] == INF) {
            return new ArrayList<>();
        }
        return dpPath[n-1];
    }
    
    private boolean isLexicographicallySmaller(List<Integer> a, List<Integer> b) {
        int len = Math.min(a.size(), b.size());
        for (int i = 0; i < len; i++) {
            if (!a.get(i).equals(b.get(i))) {
                return a.get(i) < b.get(i);
            }
        }
        return a.size() < b.size();
    }
}
