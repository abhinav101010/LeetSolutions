import java.util.*;
class Solution {
    private static final int DRAW = 0;
    private static final int MOUSE = 1;
    private static final int CAT = 2;
    public int catMouseGame(int[][] graph) {
        int n = graph.length;
        Map<String, Integer> memo = new HashMap<>();
        return dfs(1, 2, 0, graph, memo, n);
    }
    private int dfs(int mouse, int cat, int turn, int[][] graph, Map<String, Integer> memo, int n) {
        String key = mouse + "," + cat + "," + turn;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }
        if (mouse == 0) {
            memo.put(key, MOUSE);
            return MOUSE;
        }
        if (cat == mouse) {
            memo.put(key, CAT);
            return CAT;
        }
        int res;
        if (turn == 0) { // mouse turn
            int best = CAT; // worst for mouse
            for (int next : graph[mouse]) {
                int r = dfs(next, cat, 1, graph, memo, n);
                if (r == MOUSE) {
                    memo.put(key, MOUSE);
                    return MOUSE;
                }
                if (r == DRAW) {
                    best = DRAW;
                }
                // if r == CAT, best stays CAT unless we found draw
            }
            res = best;
        } else { // cat turn
            int worst = MOUSE; // best for mouse
            for (int next : graph[cat]) {
                if (next == 0) continue; // cat cannot go to hole
                int r = dfs(mouse, next, 0, graph, memo, n);
                if (r == CAT) {
                    memo.put(key, CAT);
                    return CAT;
                }
                if (r == DRAW) {
                    worst = DRAW;
                }
                // if r == MOUSE, worst stays MOUSE unless draw found
            }
            res = worst;
        }
        memo.put(key, res);
        return res;
    }
}
