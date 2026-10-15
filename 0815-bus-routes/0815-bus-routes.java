import java.util.*;
class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        Map<Integer, List<Integer>> stopToRoutes = new HashMap<>();
        for (int i = 0; i < routes.length; i++) {
            for (int stop : routes[i]) {
                stopToRoutes.computeIfAbsent(stop, k -> new ArrayList<>()).add(i);
            }
        }
        Set<Integer> visitedRoutes = new HashSet<>();
        Deque<int[]> q = new ArrayDeque<>(); // [route, buses]
        for (int rt : stopToRoutes.getOrDefault(source, Collections.emptyList())) {
            q.addLast(new int[]{rt, 1});
            visitedRoutes.add(rt);
        }
        Set<Integer> targetRoutes = new HashSet<>(stopToRoutes.getOrDefault(target, Collections.emptyList()));
        while (!q.isEmpty()) {
            int[] cur = q.removeFirst();
            int rt = cur[0];
            int buses = cur[1];
            if (targetRoutes.contains(rt)) {
                return buses;
            }
            for (int stop : routes[rt]) {
                for (int nxtRt : stopToRoutes.getOrDefault(stop, Collections.emptyList())) {
                    if (!visitedRoutes.contains(nxtRt)) {
                        visitedRoutes.add(nxtRt);
                        q.addLast(new int[]{nxtRt, buses + 1});
                    }
                }
            }
        }
        return -1;
    }
}
