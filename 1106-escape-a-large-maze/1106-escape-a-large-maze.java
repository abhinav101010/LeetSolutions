import java.util.*;
class Solution {
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        if (blocked.length == 0) return true;
        Set<String> blockedSet = new HashSet<>();
        for (int[] b : blocked) blockedSet.add(b[0] + "," + b[1]);
        int limit = blocked.length * (blocked.length - 1) / 2;
        return bfs(blockedSet, source, target, limit) && bfs(blockedSet, target, source, limit);
    }
    private boolean bfs(Set<String> blockedSet, int[] start, int[] end, int limit) {
        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{start[0], start[1]});
        Set<String> seen = new HashSet<>();
        seen.add(start[0] + "," + start[1]);
        while (!q.isEmpty() && seen.size() <= limit) {
            int[] cur = q.poll();
            if (cur[0] == end[0] && cur[1] == end[1]) return true;
            for (int[] d : new int[][]{{1,0},{-1,0},{0,1},{0,-1}}) {
                int nx = cur[0] + d[0], ny = cur[1] + d[1];
                if (nx >= 0 && nx < 1000000 && ny >= 0 && ny < 1000000 && !blockedSet.contains(nx + "," + ny) && !seen.contains(nx + "," + ny)) {
                    seen.add(nx + "," + ny);
                    q.add(new int[]{nx, ny});
                }
            }
        }
        return seen.size() > limit;
    }
}
