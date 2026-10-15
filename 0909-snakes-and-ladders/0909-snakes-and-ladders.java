import java.util.*;
class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        int[][] dirs = {}; // not needed
        // function to get row, col from label 1-indexed
        java.util.function.IntFunction<int[]> getCoord = s -> {
            int s0 = s - 1;
            int quot = s0 / n;
            int rem = s0 % n;
            int r = n - 1 - quot;
            int c = ((n - 1 - quot) % 2 == 0) ? rem : n - 1 - rem;
            return new int[]{r, c};
        };
        boolean[] visited = new boolean[n*n + 1];
        Deque<int[]> q = new ArrayDeque<>(); // [position, steps]
        q.addLast(new int[]{1, 0});
        visited[1] = true;
        while (!q.isEmpty()) {
            int[] cur = q.pollFirst();
            int s = cur[0];
            int steps = cur[1];
            if (s == n*n) {
                return steps;
            }
            for (int nxt = s+1; nxt <= Math.min(s+6, n*n); nxt++) {
                int[] rc = getCoord.apply(nxt);
                int r = rc[0], c = rc[1];
                if (board[r][c] != -1) {
                    nxt = board[r][c];
                }
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.addLast(new int[]{nxt, steps+1});
                }
            }
        }
        return -1;
    }
}
