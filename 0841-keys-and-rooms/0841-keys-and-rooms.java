import java.util.*;
class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int n = rooms.size();
        boolean[] visited = new boolean[n];
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(0);
        visited[0] = true;
        while (!stack.isEmpty()) {
            int room = stack.pop();
            for (int nxt : rooms.get(room)) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    stack.push(nxt);
                }
            }
        }
        for (boolean v : visited) {
            if (!v) return false;
        }
        return true;
    }
}
